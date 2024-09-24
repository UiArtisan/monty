#include "monty.h"

/**
 * pchar - Print the character at the top of the stack.
 * @__head: A pointer to the stack.
 * @__counter: Line counter.
 */
void pchar(stack_t **__head, unsigned int __counter)
{
	if (!*__head)
		p_error(3, ERR_PCHAR_EMPTY, __counter, __head);
	if ((*__head)->n > 127 || (*__head)->n < 0)
		p_error(3, ERR_PCHAR_OUT, __counter, __head);
	printf("%c\n", (*__head)->n);
}

/**
 * pstr - Print the string at the top of the stack.
 * @__head: A pointer to the stack.
 * @__counter: Line counter (unused).
 */
void pstr(stack_t **__head, __attribute__((unused)) unsigned int __counter)
{
	stack_t *h;

	h = *__head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
