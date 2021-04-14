#include "header_file.h"

/**
 *main - Entry point
 *Return: always (0)
 */
int main(void)
{
	int count_pro = 0, entry = 0, flag = 0, _built = 0;
	char *buff = NULL, *buff_two = NULL;
	size_t bytes = 0;

	while (entry != EOF)
	{
		count_pro++;
		if ((isatty(STDIN_FILENO)) != 0)
			write(STDOUT_FILENO, "#shellDB$ ", 10);
		entry = getline(&buff, &bytes, stdin);
		flag = _spaces(buff);
		if ((buff[0] == 10 && buff[1] == 0) || flag == -1)
			continue;
		if (entry != EOF)
		{
			buff_two = _strtok_v2(buff, " ");
			_built = _functions_shell_own(buff_two);
			if (_built == 0)
				break;
			else if (buff_two[0] == '/')
				read_path(buff_two, count_pro);
			else
				read_commands(buff_two, count_pro);
			free(buff_two);
		}
	}
	free(buff);
	if ((isatty(STDIN_FILENO)) != 0)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
