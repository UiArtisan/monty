#include "monty.h"


/**
 * get_info - Retrieve the info structure.
 *
 * This function provides access to a static info_t structure
 * containing significant program information. It returns a pointer
 * to the structure, allowing you to access or modify its members.
 *
 * Return: A pointer to the static info_t structure.
 */
info_t *get_info()
{
	static info_t info = {NULL, NULL, NULL, 0};

	return (&info);
}


/**
 * main - monty code interpreter
 * @__argc: number of arguments
 * @__argv: monty file location
 * Return: 0 on success
 */
int main(int __argc, char **__argv)
{
	char *content = NULL;
	FILE *file = NULL;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	info_t *info = get_info();

	if (__argc != 2)
		fprintf(stderr, USAGE), exit(EXIT_FAILURE);

	file = fopen(__argv[1], "r");
	info->monty_file = file;
	if (!file)
		fprintf(stderr, ERR_OPEN, __argv[1]), exit(EXIT_FAILURE);
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		info->line_content = content;
		++counter;
		if (read_line > 0)
			execute(content, &stack, counter);
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
