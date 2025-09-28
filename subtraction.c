/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{   
    if (compare_numbers(*head1, *head2) == -1) {
        // if number2 > number1 swap the lis ,so we always do larger - smaller
        swap_function(head1, tail1, head2, tail2);
    }

	Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0;

    while (temp1 != NULL) {
        int digit1 = temp1->data;
        int digit2 = (temp2 != NULL) ? temp2->data : 0;

        digit1 -= borrow;

        int res;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res = digit1 - digit2;

        if (insert_at_first(headR, tailR, res) == FAILURE) {
            return FAILURE;
        }

        temp1 = temp1->prev;
        if (temp2 != NULL) temp2 = temp2->prev;
    }
    delete_leading_zeros(headR, tailR);

    return SUCCESS;
}
