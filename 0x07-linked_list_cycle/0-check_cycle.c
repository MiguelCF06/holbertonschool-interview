#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it
 * @list: The singly linked list to check
 * Return: 0 if there is no cycle, 1 if there is cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slowPointer = list;
	listint_t *fastPointer = list;

	while (slowPointer && fastPointer && fastPointer->next)
	{
		slowPointer = slowPointer->next;
		fastPointer = fastPointer->next->next;
		if (slowPointer == fastPointer)
		{
			return (1);
		}
	}
	return (0);
}
