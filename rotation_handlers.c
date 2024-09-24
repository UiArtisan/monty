#include "monty.h"

/**
 * rotl - Rotate the stack to the top.
 * @__head: A pointer to the stack.
 * @__counter: Line counter (unused).
 */
void rotl(stack_t **__head, __attribute__((unused)) unsigned int __counter)
{
	stack_t *h = *__head, *top;

	if (!*__head || !(*__head)->next)
		return;
	top = (*__head)->next;
	top->prev = NULL;
	while (h->next)
		h = h->next;
	h->next = *__head;
	(*__head)->next = NULL;
	(*__head)->prev = h;
	(*__head) = top;
}

/**
 * rotr - Rotate the stack to the bottom.
 * @__head: A pointer to the stack.
 * @__counter: Line counter (unused).
 */
void rotr(stack_t **__head, __attribute__((unused)) unsigned int __counter)
{
	stack_t *h = *__head;

	if (!*__head || !(*__head)->next)
		return;
	while (h->next)
		h = h->next;
	h->next = *__head;
	h->prev->next = NULL;
	h->prev = NULL;
	(*__head)->prev = h;
	(*__head) = h;
}

