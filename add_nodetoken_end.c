#include "lists.h"

/**
 * add_nodetoken_end - adds a new node at the end of a listtoken_t list
 *
 * Description: function adds a new node to the end f the linked list
 *
 * @head: points to a pointer that points to the first node
 * @token: the token to add
 *
 * Return: the address of the new element, or NULL if it failed
 */
listtoken_t *add_nodetoken_end(listtoken_t **head, char *token)
{
	listtoken_t *new_node, *last_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listtoken_t));
	if (new_node == NULL)
		return (NULL);

	new_node->token = token;
	new_node->token_length = strlen(token);
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}

	return (last_node);
}
