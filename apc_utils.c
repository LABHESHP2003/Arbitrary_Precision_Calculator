#include <ctype.h>
#include <string.h>
#include "apc.h"

int validate_number(const char *num){
    if(*num == '-'){
        num++;
    }

    if(*num == '\0'){
        return FAILURE;
    }

     while (*num) {
        if (!(*num >= '0' && *num <= '9')) {
            return FAILURE;
        }
        num++;
    }
    return SUCCESS;
}


int validate_operator(const char *operator){
     if (strlen(operator) != 1 || (operator[0] != '+' && operator[0] != '-' && operator[0] != '*' && operator[0] != '/'))
    {
        return FAILURE;
    }else{
        return SUCCESS;
    }
}


int compare_numbers(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *temp1 = head1, *temp2 = head2;

    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }

    if (len1 > len2) return 1; //if number1 > number2  -> 1
    if (len1 < len2) return -1; //if number1 < number2 -> -1

    temp1 = head1;
    temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data > temp2->data) return 1;
        if (temp1->data < temp2->data) return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0; //if number1 == number2 -> 0
}

void swap_function(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2) {
    Dlist *temp_head = *head1;
    Dlist *temp_tail = *tail1;

    *head1 = *head2;
    *tail1 = *tail2;

    *head2 = temp_head;
    *tail2 = temp_tail;
}

