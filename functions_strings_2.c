#include "header_file.h"

/**
 *str_concat - concatenates two strings
 *@s1: pointer type char with a string
 *@s2: pointer type char with a string
 *Return: pointer to str or NULL (if it fails)
 */

char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, c1 = 0, c2 = 0;
	char *concat = NULL;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	concat = malloc(((i + j) + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);
	for ( ; c1 < i; c1++)
		concat[c1] = s1[c1];
	for (c1 = i; c1 <= i + j; c1++)
		concat[c1] = s2[c2], c2++;
	return (concat);
}

/**
 * _itoa - function that change a integer to string
 * @number: integer to convert
 * Return: a string with of integer
 */
char *_itoa(int number)
{
	int i = 0, j = 0, k = 0, h = 0;
	char *s = NULL, *str = NULL;

	s = _calloc(3000, sizeof(char));
	for ( ; number > 0 ; i++)
		s[i] = (number % 10) + '0', number = (number / 10);
	s[i] = '\0';
	j = _strlen(s);
	h = j;
	h--;
	str = _calloc(j + 1, sizeof(char));
	for ( ; k < j ; k++)
		str[k] = s[h], h--;
	free(s);
	str[k] = '\0';
	return (str);
}

/**
 *_strdup - function duplicate of the string
 *@str: duplicating string
 *Return: pointer to p or NULL (if it fails)
 */
char *_strdup(char *str)
{
	int i = 0, len_str = 0;
	char *p = NULL;

	if (str == NULL)
		return (NULL);
	while (str[len_str] != '\0')
		len_str++;
	p = malloc((len_str + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	for ( ; i <= len_str; i++)
		p[i] = str[i];
	return (p);
}

/**
 *relative_path - excute a relative path
 *@dp_commands: double pointer that store the information of the commmands
 *@count_pro: counter process
 */
void relative_path(char **dp_commands, int count_pro)
{
	int state = 0;
	struct stat st_s;
	pid_t child = 0;

	state = stat(dp_commands[0], &st_s);
	if (state == 0)
	{
		child = fork();
		wait(NULL);
		if (child == 0)
			execve(dp_commands[0], dp_commands, environ);
		free_dp(dp_commands);
		return;
	}
	else
		error_stat_paths_commands(dp_commands, count_pro);
	free_dp(dp_commands);
}

void signal_ctrl_c(__attribute__((unused)) int signal)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "#shellDB$ ", 10);
}
