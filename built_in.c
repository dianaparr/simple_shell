/* #include "header_file.h"

int _functions_shell_own(char *buff_two, char *buff)
{
	built_in incor[] = {
		{"exit", func_exit},
		{"env", func_env},
		{NULL, NULL}
	};
	int i = 0;

	while(*buff_two != NULL)
	{
		while(incor[i].name != NULL)
		{
			if((_strncmp(incor[i].name, *buff_two, 0) == 0)
			{	
				incor[i].ptr_func();
				return (0);
			}	
			i++;
		}
	}
	return (-1);
} */