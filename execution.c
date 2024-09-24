#include "monty.h"

/**
 * execute - Execute the opcode.
 * @__content: Line content.
 * @__stack: Head of the linked list (stack).
 * @__counter: Line counter.
 */
void execute(char *__content, stack_t **__stack,
				unsigned int __counter)
{
	instruction_t opts[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"nop", nop}, {"add", __add}, {"sub", __sub},
		{"div", __div}, {"mul", __mul}, {"mod", __mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr}, {"queue", queue},
		{"stack", stack}, {NULL, NULL}
	};
	unsigned int idx = 0;
	char *opt = NULL;
	info_t *info = get_info();

	opt = strtok(__content, " \n\t");
	if (opt && opt[0] == '#')
		return;
	info->value = strtok(NULL, " \n\t");
	for (; opts[idx].opcode && opt; ++idx)
	{
		if (strcmp(opt, opts[idx].opcode) == 0)
		{
			opts[idx].f(__stack, __counter);
			return;
		}
	}
	if (opt && !opts[idx].opcode)
		p_error(1, __counter, opt, __stack);
}
