#include "header_file.h"

int _functions_shell_own(char *buff_two)
{
	built_in incor[] = {
		{"exit", func_exit},
		{NULL, NULL},
	};

	int i = 0, count_wds = 0;
	char **command, *delim = " ";
	
	count_wds = _words(buff_two, ' ');
	command = alloc_double_pointer(count_wds, buff_two, delim);
	while(incor[i].name != NULL)
	{
		if((_strcmp(incor[i].name, command[0])) == 0)
		{	
			incor[i].ptr_func(command);
			return (0);
		}	
		i++;
	}
	return (-1);
}

int func_exit(char **command)
{
	free(command);
	exit (0);
}