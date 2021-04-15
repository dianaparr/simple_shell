#ifndef HEADER_FILE_H
#define HEADER_FILE_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct built - Struct builtin
 * @name: Specifiers of the builtin
 * @ptr_func: The function associated to each builtin
 */

typedef struct built
{
char *name;
void (*ptr_func)(char **command);
} built_in;

extern char **environ;

/* functions_shell */
void read_path(char *buff, int count_pro);
void read_commands(char *buff, int count_pro);
void create_child_commands(char **dp_path, char **dp_commands, int count_pro);
void create_child_path(char **dp, int count_pro);

/* functions_helper*/
char **alloc_double_pointer(int count_wds, char *buff, char *delim);
int _words(char *buff, char delim);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_getenv(const char *name);
int _spaces(char *buff);

/*functions_strings*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(char *s1, char *s2, size_t n_bytes);
int _strcmp(char *s1, char *s2);

/*functions_strings_2*/
char *str_concat(char *s1, char *s2);
char *_itoa(int number);
char *_strdup(char *str);
void relative_path(char *buff_two, int count_pro);
void signal_ctrl_c(__attribute__((unused)) int signal);

/*errors*/
void error_execve_paths(char **dp, int count_pro);
void error_stat_paths_commands(char **dp, int count_pro);
void free_dp(char **dp);

/*tokenizer*/
char *_strtok_v2(char *s, char *delim);

/*builtin*/
int _functions_shell_own(char *buff_two);
void func_exit(char **command);
void func_env(char **command);

#endif /* HEADER_FILE_H */
