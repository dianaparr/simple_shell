#include "header_file.h"

/**
 *_functions_shell_own - function that stores the built-in functions
 *@buff_two: buff of the getline
 *@buff: stores the information entered by the user
 *Return: 0, if built-in functions exist and -1, if no exist
 */
int _functions_shell_own(char *buff_two, char *buff)
{
	built_in incor[] = {
		{"exit", func_exit},
		{"env", func_env},
		{NULL, NULL},
	};

	int i = 0, count_wds = 0, j = 0;
	char **command, *delim = " ";

	count_wds = _words(buff_two, ' ');
	command = alloc_double_pointer(count_wds, buff_two, delim);
	while (incor[i].name != NULL)
	{
		if ((_strcmp(incor[i].name, command[0])) == 0)
		{
			j = incor[i].ptr_func(command);
			if (j == 1)
				free(buff), free(buff_two), exit(127);
			free(buff_two);
			return (0);
		}
		i++;
	}
	free_dp(command);
	return (-1);
}

/**
 *func_exit - function for exit of the program
 *@command: double pointer that store the information passed by the user
 *Return: a flag that indicate the program out
 */
int func_exit(char **command)
{
	free_dp(command);
	return (1);
}
/**
 *func_env - function that print the environment
 *@command: double pointer that store the information passed by the user
 *Return: a flag that indicate the continue
 */
int func_env(char **command)
{
	int i = 0;

	for ( ; environ[i] != NULL; i++)
		write(STDOUT_FILENO, environ[i], _strlen(environ[i])),
		write(STDOUT_FILENO, "\n", 2);
	free_dp(command);
	return (0);
}
