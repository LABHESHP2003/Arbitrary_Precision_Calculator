/***************************************************************************************************
 * Title       : Multiplication
 * Description : Multiplies two large numbers represented as doubly linked lists and stores the
 *               product in the resultant list.
 * Prototype   : int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
 * Input       : head1, tail1 - pointers to first and last nodes of the first number's list
 *               head2, tail2 - pointers to first and last nodes of the second number's list
 *               headR, tailR - pointers to first and last nodes of the result list
 * Output      : SUCCESS on successful multiplication, FAILURE otherwise
 ***************************************************************************************************/

#include "apc.h"
#include <stdlib.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	// If any operand is zero, result is zero
	if ((*head1 == *tail1 && (*head1)->data == 0) || (*head2 == *tail2 && (*head2)->data == 0))
	{
		if (insert_at_last(headR, tailR, 0) == FAILURE)
		{
			free_list(headR, tailR);
			return FAILURE;
		}
		return SUCCESS;
	}

	Dlist *result_head = NULL, *result_tail = NULL;
	int zero_count = 0;

	// Traverse tail2 from last digit (least significant digit)
	for (Dlist *p2 = *tail2; p2 != NULL; p2 = p2->prev, zero_count++)
	{
		Dlist *temp_head = NULL, *temp_tail = NULL;

		// Add zeros at the end to shift the digits according to place value
		for (int i = 0; i < zero_count; i++)
		{
			if (insert_at_last(&temp_head, &temp_tail, 0) == FAILURE)
			{
				free_list(&temp_head, &temp_tail);
				free_list(&result_head, &result_tail);
				return FAILURE;
			}
		}

		int carry = 0;
		// Multiply p2's digit by every digit of first number
		for (Dlist *p1 = *tail1; p1 != NULL; p1 = p1->prev)
		{
			int mul = p1->data * p2->data + carry;
			if (insert_at_first(&temp_head, &temp_tail, mul % 10) == FAILURE)
			{
				free_list(&temp_head, &temp_tail);
				free_list(&result_head, &result_tail);
				return FAILURE;
			}
			carry = mul / 10;
		}

		if (carry)
		{
			if (insert_at_first(&temp_head, &temp_tail, carry) == FAILURE)
			{
				free_list(&temp_head, &temp_tail);
				free_list(&result_head, &result_tail);
				return FAILURE;
			}
		}

		if (!result_head)
		{
			result_head = temp_head;
			result_tail = temp_tail;
		}
		else
		{
			Dlist *sum_head = NULL, *sum_tail = NULL;
			if (addition(&result_head, &result_tail, &temp_head, &temp_tail, &sum_head, &sum_tail) == FAILURE)
			{
				free_list(&temp_head, &temp_tail);
				free_list(&result_head, &result_tail);
				return FAILURE;
			}

			free_list(&result_head, &result_tail);
			free_list(&temp_head, &temp_tail);

			result_head = sum_head;
			result_tail = sum_tail;
		}
	}

	*headR = result_head;
	*tailR = result_tail;
	return SUCCESS;
}
