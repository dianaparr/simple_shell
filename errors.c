#include "header_file.h"

/**
 *error_execve_paths - error printed when execve fails
 *@dp: double pointer that contains the information passed on by the user
 *@count_pro: process counter for errors
 *Return: nothing
 */
void error_execve_paths(char **dp, int count_pro)
{
	char *number = NULL, *er = "Permission denied\n";

	number = _itoa(count_pro), write(STDOUT_FILENO, number, _strlen(number)),
	write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, dp[0], _strlen(dp[0])),
	write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, er, _strlen(er));
	free(number);
}

/**
 *error_stat_paths_commands - when stat fails, it does not find the command
 *@dp: double pointer that contains the information passed on by the user
 *@count_pro: process counter for errors
 *Return: nothing
 */
void error_stat_paths_commands(char **dp, int count_pro)
{
	char *number = NULL, *er = "not found\n";

	number = _itoa(count_pro),
	write(STDOUT_FILENO, number, _strlen(number)), write(STDOUT_FILENO, ": ", 2),
	write(STDOUT_FILENO, dp[0], _strlen(dp[0])),
	write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, er, _strlen(er));
	free_dp(dp);
	free(number);
	exit(127);
}

/**
 * free_dp - free a double pointer
 * @dp: double pointer
 */
void free_dp(char **dp)
{
	int i = 0;

	while (dp[i])
		free(dp[i]), i++;
	free(dp);
}
