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
 *@buff_two: stores the information entered by the user
 *@count_pro: counter process
 */
void relative_path(char *buff_two, int count_pro)
{
	int state = 0, count_wds = 0;
	char **dp = NULL;
	struct stat st_s;
	pid_t child = 0;

	count_wds = _words(buff_two, ' ');
	dp = alloc_double_pointer(count_wds, buff_two, " ");
	state = stat(dp[0], &st_s);
	if (state == 0)
	{
		child = fork();
		wait(NULL);
		if (child == 0)
			execve(dp[0], dp, environ);
		free_dp(dp), free(buff_two);
		return;
	}
	else
		error_stat_paths_commands(dp, count_pro);
	free(buff_two);
}

/**
 *signal_ctrl_c - sends a signal when ctrl+c is pressed
 *@signal: a signal that is emitted when the user enters ctrl+c
 */
void signal_ctrl_c(__attribute__((unused))int signal)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "#shellDB$ ", 10);
}
