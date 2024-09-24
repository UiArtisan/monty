#include "monty.h"

/**
 * push - Pushes an element onto the stack or queue.
 * @__head: A pointer to a pointer to the stack/queue.
 * @__counter: Line counter.
 */
void push(stack_t **__head, unsigned int __counter)
{
	int nbr, idx = 0, flag = 0;
	info_t *info = get_info();

	if (info->value)
	{
		if (info->value[0] == '-')
			++idx;
		for (; info->value[idx]; ++idx)
			if (info->value[idx] > 57 || info->value[idx] < 48)
				flag = 1;
	}
	if (flag || !info->value)
		p_error(3, ERR_PUSH, __counter, __head);
	nbr = atoi(info->value);
	if (info->stack_mode)
		add_queue(__head, nbr);
	else
		add_node(__head, nbr);
}

/**
 * pall - Prints all elements of the stack.
 * @__head: A pointer to the stack.
 * @__counter: Line counter (unused).
 */
void pall(stack_t **__head, __attribute__((unused)) unsigned int __counter)
{
	stack_t *h;

	h = *__head;
	if (!h)
		return;
	while (h)
		printf("%d\n", h->n), h = h->next;
}

/**
 * pint - Print the top element of the stack.
 * @__head: A pointer to the stack.
 * @__counter: Line counter.
 */
void pint(stack_t **__head, unsigned int __counter)
{
	if (!*__head)
		p_error(3, ERR_PINT, __counter, __head);
	printf("%d\n", (*__head)->n);
}
