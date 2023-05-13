#ifndef LISTS_H_
#define LISTS_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listtoken_s - singly linked list
 * @token: pointer
 * @token_length: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listtoken_s
{
	char *token;
	int token_length;
	struct listtoken_s *next;
} listtoken_t;

size_t print_listtoken(const listtoken_t *head);
size_t listtoken_len(const listtoken_t *head);
listtoken_t *add_nodetoken_end(listtoken_t **head, char *token);
void free_listtoken(listtoken_t **head);

#endif
