#include "lists.h"

/**
 * free_listtoken2 - frees a listtoken_t list
 * @head: points to a pointer that points to the first node
 *
 * Return: void
 */
void free_listtoken(listtoken_t **head)
{
	listtoken_t *ptr;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		ptr = *head;
		*head = ptr->next;
		free(ptr->token);
		free(ptr);
	}
	head = NULL;
}
