#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int validate_number(const char *num);
int validate_operator(const char *operator);
int create_list_from_string(const char *num, Dlist **head, Dlist **tail);
int insert_at_last(Dlist **head, Dlist **tail, int data);
int insert_at_first(Dlist **head, Dlist **tail, int data);
int delete_at_first(Dlist **head,Dlist **tail);
void delete_leading_zeros(Dlist **head, Dlist **tail);
int compare_numbers(Dlist *head1, Dlist *head2);
void print_list(Dlist *head);
void swap_function(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
void free_list(Dlist **head, Dlist **tail);


int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);


#endif
