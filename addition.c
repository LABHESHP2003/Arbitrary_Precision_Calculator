/***************************************************************************************************
 * Title       : Addition
 * Description : Adds two large numbers represented as doubly linked lists and stores the result
 *               in a resultant doubly linked list.
 * Prototype   : int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
 * Input       : head1, tail1 - pointers to first and last nodes of first number's list
 *               head2, tail2 - pointers to first and last nodes of second number's list
 *               headR, tailR - pointers to first and last nodes of the result list
 * Output      : SUCCESS on successful addition, FAILURE otherwise
 ***************************************************************************************************/

#include "apc.h"
#include <stdlib.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int digit1 = (temp1) ? temp1->data : 0;
        int digit2 = (temp2) ? temp2->data : 0;

        int sum = digit1 + digit2 + carry;
        int res = sum % 10;
        carry = sum / 10;

        // Insert the result digit at the front of the result list
        if (insert_at_first(headR, tailR, res) == FAILURE)
        {
            return FAILURE;
        }

        if (temp1)
        {
            temp1 = temp1->prev;
        }
        if (temp2)
        {
            temp2 = temp2->prev;
        }
    }

    return SUCCESS;
}
