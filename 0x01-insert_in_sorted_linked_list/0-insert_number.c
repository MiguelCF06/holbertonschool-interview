#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Head of the linked list
 * @number: Number to insert.
 * Return: The address of the new node or NULL if it failed.
 **/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode, *headClone;

	headClone = *head;
	newNode = malloc(sizeof(listint_t));

	if (!newNode)
		return (NULL);

	newNode->n = number;

	if (!*head)
	{
		newNode->next = NULL;
		*head = newNode;
		return (newNode);
	}

	if (headClone->n > newNode->n)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	while (headClone->next)
	{
		if (headClone->next->n >= newNode->n)
		{
			newNode->next = headClone->next;
			headClone->next = newNode;
			return (newNode);
		}
		headClone = headClone->next;
	}
	newNode->next = headClone->next;
	headClone->next = newNode;
	return (newNode);
}
