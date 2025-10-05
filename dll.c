/*******************************************************************************************************************************************************************
 * Title       : dll.c
 * Description : Implements doubly linked list functions for arbitrary precision arithmetic, including list creation,
 *               insertion, deletion, printing, memory cleanup, and removing leading zeros.
 * Prototypes  : create_list_from_string, insert_at_last, insert_at_first, delete_at_first, print_list, free_list, delete_leading_zeros
 * Inputs      : Strings and pointers to list heads/tails
 * Outputs     : Success/failure codes or modifies lists and memory
 *******************************************************************************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "apc.h"

int create_list_from_string(const char *num, Dlist **head, Dlist **tail)
{
    int size = strlen(num);

    char temp[2];

    *head = NULL;
    *tail = NULL;

    for (int i = 0; i < size; i++)
    {
        temp[0] = num[i];
        temp[1] = '\0';

        int data = atoi(temp);
        if (insert_at_last(head, tail, data) == FAILURE)
        {
            printf("Error: Creating linked list of operands.\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}

int insert_at_last(Dlist **head, Dlist **tail, int data)
{

    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
        printf("Error: Memory Allocation Failed\n");
        return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    // list empty
    if (*head == NULL && *tail == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }
    else
    { // non empty list
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
        return SUCCESS;
    }
}

int insert_at_first(Dlist **head, Dlist **tail, int data)
{

    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
        printf("Error: Memory Allocation Failed\n");
        return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = *head;

    // list empty
    if (*head == NULL && *tail == NULL)
    {
        *head = *tail = new;
    }
    else
    { // non empty list
        (*head)->prev = new;
        *head = new;
    }
    return SUCCESS;
}

int delete_at_first(Dlist **head, Dlist **tail)
{
    // empty list
    if (*head == NULL && *tail == NULL)
    {
        return FAILURE;
    }
    // only single node in list
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = *tail = NULL;
        return SUCCESS;
    }
    // non empty list
    Dlist *temp = *head;
    *head = temp->next;
    (*head)->prev = NULL;
    free(temp);
    return SUCCESS;
}

void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Dlist *temp = head;

    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void free_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    Dlist *next_node = NULL;

    while (temp != NULL)
    {
        next_node = temp->next;
        free(temp);
        temp = next_node;
    }

    *head = NULL;
    *tail = NULL;
}

void delete_leading_zeros(Dlist **head, Dlist **tail)
{
    while ((*head)->data == 0 && (*head)->next != NULL)
    {
        delete_at_first(head, tail);
    }
}