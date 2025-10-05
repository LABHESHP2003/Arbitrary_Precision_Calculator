/***************************************************************************************************
 * Title       : Division
 * Description : Performs division of two large numbers represented as doubly linked lists and stores
 *               the quotient in the resultant list.
 * Prototype   : int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
 * Input       : head1, tail1 - pointers to first and last nodes of the dividend list
 *               head2, tail2 - pointers to first and last nodes of the divisor list
 *               headR, tailR - pointers to first and last nodes of the quotient/result list
 * Output      : SUCCESS on successful division, FAILURE otherwise
 ***************************************************************************************************/

#include "apc.h"
#include <stdlib.h>

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *head_sum = NULL, *tail_sum = NULL;
    Dlist *head_count = NULL, *tail_count = NULL;
    Dlist *head_one = NULL, *tail_one = NULL;

    Dlist *head_res = NULL, *tail_res = NULL;
    Dlist *head_cnt = NULL, *tail_cnt = NULL;

    // sum = 0, count = 0, one = 1
    create_list_from_string("0", &head_sum, &tail_sum);
    create_list_from_string("0", &head_count, &tail_count);
    create_list_from_string("1", &head_one, &tail_one);

    while (1)
    {
        // res = sum + divisor
        head_res = tail_res = NULL;
        addition(&head_sum, &tail_sum, head2, tail2, &head_res, &tail_res);

        // if res > dividend -> break
        if (compare_numbers(head_res, *head1) > 0)
        {
            free_list(&head_res, &tail_res);
            break;
        }

        // sum = res
        free_list(&head_sum, &tail_sum);
        head_sum = head_res;
        tail_sum = tail_res;

        // cnt = count + 1
        head_cnt = tail_cnt = NULL;
        addition(&head_count, &tail_count, &head_one, &tail_one, &head_cnt, &tail_cnt);

        free_list(&head_count, &tail_count);
        head_count = head_cnt;
        tail_count = tail_cnt;
    }

    // Clean up
    free_list(&head_sum, &tail_sum);
    free_list(&head_one, &tail_one);

    *headR = head_count;
    *tailR = tail_count;
    return SUCCESS;
}
