#include "header_file.h"

void read_path(char *buff, int count_pro)
{
	int count_wds = 0, state = 0;
	char **dp = NULL, *delim = NULL;
	struct stat st_s;

	delim = " ";
	count_wds = _words(buff);
	dp = alloc_double_pointer(count_wds, buff, delim);
	state = stat(dp[0], &st_s);
	if (state == 0)
	{
		if ((execve(dp[0], dp, NULL) == -1))
		{	
			perror("execve");
			exit(1);
		}	
		
	}		 
	else
		/* write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, buff, strlen(s)), write(STDOUT_FILENO, ":", 1), write(STDOUT_FILENO, "not found", 9); */
		printf("%d: %s: Not Found\n", count_pro, buff);
	free(dp);
	free(buff);
	exit(1);
}