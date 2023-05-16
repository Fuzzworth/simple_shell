#include "lists.h"

/**
 * free_listtoken - frees a listtoken_t list
 *
 * Description: free a listtoken_t list
 *
 * @head: points to a pointer that points to the first node
 *
 * Return: void
 */
void free_listtoken(listtoken_t **head)
{
	listtoken_t *node;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		node = *head;
		*head = node->next;
		free(node->token);
		free(node);
	}
	head = NULL;
}
