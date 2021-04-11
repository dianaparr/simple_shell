#include "header_file.h"

void read_path(char *buff, int count_pro)
{
	int count_wds = 0, state = 0;
	char **dp = NULL, *delim = NULL;
	struct stat st_s;
	int p;

	delim = " ";
	count_wds = _words(buff);
	dp = alloc_double_pointer(count_wds, buff, delim);
	state = stat(dp[0], &st_s);
	if (state == 0)
	{
		if (((p = execve(dp[0], dp, NULL)) == -1))
		{
			printf("%d: %s: Permission denied\n", count_pro, buff);
			/*perror("execve");*/
			free(dp);
			free(buff);
			exit(1);
		}	
		
	}		 
	else
		/* write(STDOUT_FILENO, ": ", 2), write(STDOUT_FILENO, buff, strlen(s)), write(STDOUT_FILENO, ":", 1), write(STDOUT_FILENO, "not found", 9); */
		printf("%d: %s: not found\n", count_pro, buff);
	free(dp);
	free(buff);
	exit(1);
}

void read_commands(char *buff, int count_pro)
{
	int count_wds_path = 0, counts_path = 0, count_wds_commands = 0, r_ex = 0;
	char  *_path = NULL, *dest = NULL, **dp_path = NULL,
		*delim1 = NULL, *delim2 = NULL, **dp_commands = NULL;
	DIR *o_dir;
	struct dirent *r_dir;

	delim1 = ":";
	delim2 = " ";
	_path = _getenv("PATH");
	/* path */
	count_wds_path = _words(_path);
	dp_path = alloc_double_pointer(count_wds_path, _path, delim1);
	/* commands */
	count_wds_commands = _words(buff);
	dp_commands = alloc_double_pointer(count_wds_commands, buff, delim2);
	while (dp_path[counts_path] != NULL)
	{
		o_dir = opendir(dp_path[counts_path]);
		while ((r_dir = readdir(o_dir)) != NULL)
		{
			if (_strcmp(r_dir->d_name, dp_commands[0]) == 0)
			{
				_strcat(dp_path[counts_path], "/");
				dest = _strcat(dp_path[counts_path], dp_commands[0]);
				r_ex = execve(dest, dp_commands, NULL);
				if (r_ex == -1)
					printf("%d: %s: not found\n", count_pro, buff), free(dp_path), free(dp_commands), free(buff), exit(-1);
				closedir(o_dir);
				dp_path = NULL;
				break;
			}
		}
		closedir(o_dir);
		counts_path++;
	}
	printf("%d: %s: not found\n", count_pro, buff);
	free(dp_path);
	free(dp_commands);
	free(buff);
	exit(1);
}

/**
 * _strcat - Entry point
 * @src: source
 * @dest: dest
 * Return: -
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, counter = 0;

	for ( ; dest[i] != '\0'; i++)
	{
		counter++;
	}
	for ( ; src[j] != '\0'; j++)
	{
		dest[counter + j] = src[j];
	}
	dest[counter + j] = '\0';
	return (dest);
}
