#include "header_file.h"

/**
 *read_path - reads the paths that the user enters
 *@buff: stores the information entered by the user
 *@count_pro: counter process
 */
void read_path(char *buff, int count_pro)
{
	int count_wds = 0, state = 0;
	char **dp = NULL, *delim = " ";
	struct stat st_s;

	count_wds = _words(buff, ' ');
	dp = alloc_double_pointer(count_wds, buff, delim);
	state = stat(dp[0], &st_s);
	if (state == 0)
		create_child_path(dp, count_pro), free(dp);
	else
		error_stat_paths_commands(dp, count_pro), free(dp);
}

/**
 *read_commands - reads the commands that the user enters
 *@buff: stores the information entered by the user
 *@count_pro: counter process
 */
void read_commands(char *buff, int count_pro)
{
	int count_wds_path = 0, count_wds_commands = 0;
	char  *_path = NULL, **dp_path = NULL,
		*delim1 = ":", *delim2 = " ", **dp_commands = NULL;

	_path = _getenv("PATH");
	/* path */
	count_wds_path = _words(_path, ':');
	dp_path = alloc_double_pointer(count_wds_path, _path, delim1);
	/* commands */
	count_wds_commands = _words(buff, ' ');
	dp_commands = alloc_double_pointer(count_wds_commands, buff, delim2);
	create_child_commands(dp_path, dp_commands, count_pro);
	free_dp(dp_path), free_dp(dp_commands); /*exit(1);*/
}

/**
 *create_child_commands - create the child process to execute commands
 *@dp_path: double pointer that store the information of the $PATH
 *@dp_commands: double pointer that store the information of the commmands
 *@count_pro: counter process
 */
void create_child_commands(char **dp_path, char **dp_commands, int count_pro)
{
	int state = 0, i = 0;
	char *concat = NULL, *concat_2 = NULL;
	pid_t child = 0;
	struct stat st_s;


	while (dp_path[i] != NULL)
	{
		concat = str_concat(dp_path[i], "/");
		concat_2 = str_concat(concat, dp_commands[0]);
		state = stat(concat_2, &st_s);
		if (state == 0)
		{
			child = fork();
			wait(NULL);
			if (child == 0)
				execve(concat_2, dp_commands, environ);
			free(concat), free(concat_2);
			return;
		}
		i++;
	}
	/* child = fork();
	wait(NULL);
	if (child == 0) */
		error_stat_paths_commands(dp_commands, count_pro);
	free(concat), free(concat_2);
}

/**
 *create_child_path - create the child process to execute path
 *@dp: double pointer that store the information of the path
 *@count_pro: counter process
 */
void create_child_path(char **dp, int count_pro)
{
	pid_t child = 0;

	child = fork();
	if (child == 0)
	{
		if ((execve(dp[0], dp, environ) == -1))
			error_execve_paths(dp, count_pro), exit(1);
	}
	else if (child == -1)
		write(STDOUT_FILENO, "Error\n", 6);
	else
		wait(NULL);
	return;
}
