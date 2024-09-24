#include "monty.h"

/**
 * stack - Change the mode to stack.
 * @__head: A pointer to the stack (unused).
 * @__counter: Line counter (unused).
 */
void stack(stack_t **__head, unsigned int __counter)
{
	info_t *info;

	(void)__head;
	(void)__counter;

	info = get_info();
	info->stack_mode = 0;
}

/**
 * add_node - Add an element to the stack.
 * @__head: A pointer to the stack.
 * @__nbr: The value to be added.
 */
void add_node(stack_t **__head, int __nbr)
{
	stack_t *new_node, *current;

	current = *__head;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		p_error(2);
	if (current)
		current->prev = new_node;
	new_node->n = __nbr;
	new_node->prev = NULL;
	new_node->next = *__head;
	*__head = new_node;
}

/**
 * free_stack - Free a doubly linked list.
 * @__head: A pointer to the head of the list.
 */
void free_stack(stack_t *__head)
{
	stack_t *h;

	h = __head;
	while (__head)
	{
		h = __head->next;
		free(__head);
		__head = h;
	}
}
