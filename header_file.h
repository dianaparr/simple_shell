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

void read_path(char *buff, int count_pro);
char **alloc_double_pointer(int count_wds, char *buff, char *delim);
void free_double_pointer(char **buff, int count_wds);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strtok(char *s, char *delim);
int _words(char *buff);

#endif /* HEADER_FILE_H */