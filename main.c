/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"

int main(int argc, char *argv[])
{
	// Read and Validate the inputs
	if (argc != 4)
	{
		printf("Usage: ./apc <operand1> <operator> <operand2>\n");
		return FAILURE;
	}

	// Extract arguments
	char *num1 = argv[1];
	char *operator = argv[2];
	char *num2 = argv[3];

	// Validate the numbers
	if (validate_number(num1) == FAILURE || validate_number(num2) == FAILURE)
	{
		printf("Error: Invalid input. Please enter valid integers only.\n");
		return FAILURE;
	}

	if (validate_operator(operator) == FAILURE)
	{
		printf("Error: Invalid input. Please use only one of the supported operators: +,-,*,/.\n");
		return FAILURE;
	}

	if (operator[0] == '/' && strcmp(num2, "0") == 0)
	{
		printf("Error: Division by zero is undefined. Please enter a non-zero divisor.\n");
		return FAILURE;
	}

	if (operator[0] == '/' && strcmp(num1, "0") == 0)
	{
		printf("0");
		return SUCCESS;
	}

	// sign
	int sign1 = 1, sign2 = 1, signR = 1;
	if (num1[0] == '-')
	{
		sign1 = -1;
		num1++;
	}
	if (num2[0] == '-')
	{
		sign2 = -1;
		num2++;
	}

	// Declare the pointers
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

	create_list_from_string(num1, &head1, &tail1);
	delete_leading_zeros(&head1, &tail1);
	create_list_from_string(num2, &head2, &tail2);
	delete_leading_zeros(&head2, &tail2);

	int status = FAILURE; // to keep track of success or failure

	/* Function for extracting the operator */
	switch (operator[0])
	{
	case '+':
		if (sign1 == 1 && sign2 == 1)
		{
			// +a + +b = +(a + b)
			if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			{
				print_list(headR);
				status = SUCCESS;
			}
			else
				status = FAILURE;
		}
		else if (sign1 == -1 && sign2 == -1)
		{
			// -a + -b = -(a + b)
			printf("-");
			if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			{
				print_list(headR);
				status = SUCCESS;
			}
			else
				status = FAILURE;
		}
		else if (sign1 == 1 && sign2 == -1)
		{
			// +a + (-b) = a - b
			int cmp = compare_numbers(head1, head2);
			if (cmp >= 0)
			{
				// result is positive
				if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
			else
			{
				// result is negative
				printf("-");
				if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
		}
		else if (sign1 == -1 && sign2 == 1)
		{
			// -a + b = b - a
			int cmp = compare_numbers(head1, head2);
			if (cmp <= 0)
			{
				// result is positive
				if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
			else
			{
				// result is negative
				printf("-");
				if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
		}
		break;

	case '-':
		if (sign1 == 1 && sign2 == 1)
		{
			// a - b
			int cmp = compare_numbers(head1, head2);
			if (cmp >= 0)
			{
				if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
			else
			{
				printf("-");
				if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
		}
		else if (sign1 == -1 && sign2 == -1)
		{
			// -a - (-b) = b - a
			int cmp = compare_numbers(head1, head2);
			if (cmp <= 0)
			{
				if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
			else
			{
				printf("-");
				if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS)
				{
					print_list(headR);
					status = SUCCESS;
				}
				else
					status = FAILURE;
			}
		}
		else if (sign1 == 1 && sign2 == -1)
		{
			// a - (-b) = a + b
			if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			{
				print_list(headR);
				status = SUCCESS;
			}
			else
				status = FAILURE;
		}
		else if (sign1 == -1 && sign2 == 1)
		{
			// -a - b = -(a + b)
			printf("-");
			if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			{
				print_list(headR);
				status = SUCCESS;
			}
			else
				status = FAILURE;
		}
		break;

	case '*':
    if (sign1 == sign2) {
        // Result is positive if signs are same
        if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
            print_list(headR);
            status = SUCCESS;
        } else {
            status = FAILURE;
        }
    } else {
        // Result is negative if signs differ
        printf("-");
        if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
            print_list(headR);
            status = SUCCESS;
        } else {
            status = FAILURE;
        }
    }
    break;

	case '/':
    // Handle division
    // Division sign: result is positive if signs are same, negative otherwise
    if (sign1 == sign2)
    {
        if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
        {
            print_list(headR);
            status = SUCCESS;
        }
        else
            status = FAILURE;
    }
    else
    {
        // Result negative
        printf("-");
        if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
        {
            print_list(headR);
            status = SUCCESS;
        }
        else
            status = FAILURE;
    }
    break;

	default:
		printf("Invalid Input:-( Try again...\n");
		status = FAILURE;
		break;
	}

	// After switch block, free all lists
	free_list(&head1, &tail1);
	free_list(&head2, &tail2);
	free_list(&headR, &tailR);

	return status;
}
