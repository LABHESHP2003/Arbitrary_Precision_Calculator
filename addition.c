/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdlib.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) {
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL || carry != 0) {
        int digit1 = (temp1) ? temp1->data : 0;
        int digit2 = (temp2) ? temp2->data : 0;
 
        int sum = digit1 + digit2 + carry;
        int res = sum % 10;
        carry = sum / 10;

        // Insert the result digit at the front of the result list
        if(insert_at_first(headR, tailR, res) == FAILURE) {
            return FAILURE;
        }

        if(temp1){
			temp1 = temp1->prev;
		}
        if(temp2){
			temp2 = temp2->prev;
		}
    }

    return SUCCESS;
}
