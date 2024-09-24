#include "monty.h"

/**
 * p_error - Print an error message and exit.
 * @__error_code: The error code.
 */
void p_error(int __error_code, ...)
{
	va_list args;
	char *opt;
	int line_nbr;
	info_t *info = get_info();
	stack_t **head;

	va_start(args, __error_code);
	switch (__error_code)
	{
		case 1:
			line_nbr = va_arg(args, int);
			opt = va_arg(args, char *);
			fprintf(stderr, INVALID_INST, line_nbr, opt);
			break;
		case 2:
			fprintf(stderr, MALLOC_FAILD);
			break;
		case 3:
			opt = va_arg(args, char *);
			line_nbr = va_arg(args, int);
			fprintf(stderr, opt, line_nbr);
			break;
		default:
			break;
	}
	fclose(info->monty_file);
	free(info->line_content);
	head = va_arg(args, stack_t **);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
