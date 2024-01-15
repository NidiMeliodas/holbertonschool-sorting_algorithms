#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *sorted, *current, *next, *temp;

	current = *list;

	while (current != NULL)
	{
		next = current->next;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;
			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			current->prev = temp;
			temp->next = current;
		}
		print_list(*list);
		current = next;
	}
	*list = sorted;
}
