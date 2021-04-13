#include "header_file.h"

void error_execve_paths(char **dp, int count_pro)
{
	char *number = NULL, *er = "Permission denied\n";

	number = _itoa(count_pro), write(STDOUT_FILENO, number, _strlen(number)),
	write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, dp[0], _strlen(dp[0])),
	write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, er, _strlen(er));
	free(number);
}

void error_stat_paths(char **dp, int count_pro)
{
	char *number = NULL, *er = "not found\n";

	number = _itoa(count_pro),
	write(STDOUT_FILENO, number, _strlen(number)), write(STDOUT_FILENO, ": ", 2),
	write(STDOUT_FILENO, dp[0], _strlen(dp[0])),
	write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, er, _strlen(er));
	free(number);
}
