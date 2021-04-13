#include "header_file.h"

int main(void)
{
	int count_pro = 0, entry = 0;
	char *buff = NULL, *buff_two = NULL;
	size_t bytes = 0;
	pid_t child = 0;
	
	while(entry != EOF)
	{
		count_pro++;
		if ((isatty(STDIN_FILENO)) != 0)
			write(STDOUT_FILENO, "#shellDB$ ", 10);
		entry = getline(&buff, &bytes, stdin);
		buff[entry - 1] = '\0';
		if (entry != EOF)
		{
			child = fork();
			if (child == 0)
			{
				buff_two = _strtok_v2(buff, " ");
				if (buff_two[0] == '/')
					read_path(buff_two, buff, count_pro);
				else
					read_commands(buff_two, buff, count_pro);
				free(buff_two);
				free(buff);
			}
			else if (child == -1)
				free(buff), write(STDOUT_FILENO, "Error\n", 6);
			else
				wait(NULL);
		}
	}
	free(buff);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
