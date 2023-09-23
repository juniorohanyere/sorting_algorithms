#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/**
 * swap_nodes - swaps the value of two listint_t nodes
 *
 * @list: pointer to the head of the linked list
 * @node_a: the first node
 * @node_b: the second node
 *
 * Return: return nothing
*/

void swap_nodes(listint_t **list, listint_t **node_a, listint_t *node_b)
{
	(*node_a)->next = node_b->next;

	if (node_b->next != NULL)
		node_b->next->prev = *node_a;

	node_b->prev = (*node_a)->prev;
	node_b->next = *node_a;

	if ((*node_a)->prev != NULL)
		(*node_a)->prev->next = node_b;
	else
		*list = node_b;

	(*node_a)->prev = node_b;
	*node_a = node_b->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *			 order
 *
 * @list: the doubly linked list of integers to sort
 *
 * Return: return nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *h, *i, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (h = (*list)->next; h != NULL; h = tmp)
	{
		tmp = h->next;
		i = h->prev;

		while (i != NULL && h->n < i->n)
		{
			swap_nodes(list, &i, h);
			print_list((const listint_t *)*list);
		}
	}
}
