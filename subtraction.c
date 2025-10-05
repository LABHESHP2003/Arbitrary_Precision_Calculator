/***************************************************************************************************
 * Title       : Subtraction
 * Description : Subtracts two large numbers represented as doubly linked lists and stores the
 *               result in the resultant list. If the second number is larger, the lists are swapped
 *               to ensure subtraction is always performed as larger minus smaller.
 * Prototype   : int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
 * Input       : head1, tail1 - pointers to first and last nodes of the first number's list
 *               head2, tail2 - pointers to first and last nodes of the second number's list
 *               headR, tailR - pointers to first and last nodes of the result list
 * Output      : SUCCESS on successful subtraction, FAILURE otherwise
 ***************************************************************************************************/

#include "apc.h"
#include <stdio.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    if (compare_numbers(*head1, *head2) == -1)
    {
        // if number2 > number1 swap the lis ,so we always do larger - smaller
        swap_function(head1, tail1, head2, tail2);
    }

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0;

    while (temp1 != NULL)
    {
        int digit1 = temp1->data;
        int digit2 = (temp2 != NULL) ? temp2->data : 0;

        digit1 -= borrow;

        int res;
        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        res = digit1 - digit2;

        if (insert_at_first(headR, tailR, res) == FAILURE)
        {
            return FAILURE;
        }

        temp1 = temp1->prev;
        if (temp2 != NULL)
            temp2 = temp2->prev;
    }
    delete_leading_zeros(headR, tailR);

    return SUCCESS;
}
