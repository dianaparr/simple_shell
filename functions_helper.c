#include "header_file.h"

/**
 *alloc_double_pointer - create and store information in a double pointer
 *@count_wds: counter of words entered by the user
 *@buff: stores the information entered by the user
 *@delim: separator
 *Return: the double pointer with the stored information
 */
char **alloc_double_pointer(int count_wds, char *buff, char *delim)
{
	int i = 0;
	char **buff_two = NULL, *p = NULL, *buff_copy = NULL;

	buff_two = malloc((count_wds + 1) * sizeof(char *));
	if (buff_two == NULL)
		return (NULL);
	buff_copy = _strdup(buff);
	for ( ; i < count_wds; i++)
	{
		if (i == 0)
			p = _strdup(strtok(buff_copy, delim));
		else
			p = _strdup(strtok(NULL, delim));
		buff_two[i] = p;
	}
	buff_two[i] = NULL;
	free(buff_copy);
	return (buff_two);
}

/**
 *_words - word count
 *@buff: stores the information entered by the user
 *@delim: separator
 *Return: number of words
 */
int _words(char *buff, char delim)
{
	int i = 0, num_words = 0;

	for ( ; buff[i] != '\0'; i++)
	{
		if (delim == buff[i])
			num_words++;
	}
	return (num_words + 1);
}

/**
 *_calloc - function that allocates memory for an array
 *@nmemb: number of memory blocks
 *@size: size of each block
 *Return: pointer to mem_arr or NULL (if it fails)
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *mem_arr = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem_arr = malloc(nmemb * size);
	if (mem_arr == NULL)
		return (NULL);
	for ( ; i < (nmemb * size); i++)
		mem_arr[i] = 0;
	return (mem_arr);
}

/**
 *_getenv - scans the environment until a environment variable is found
 *@name: name of environment variable
 *Return: the value of the environment variable
 */
char *_getenv(const char *name)
{
	int i = 0;
	unsigned int len = 0;
	char *val = NULL, *add = NULL;

	len = _strlen((char *)name);
	for ( ; environ[i] != NULL; i++)
	{
		add = environ[i];
		val = _strchr(add, '=');
		if (val && (((val - add) == len) && !_strncmp(add, (char *)name, len)))
			return (val + 1);
	}
	return (NULL);
}

/**
 *_spaces - confirms if there are only space at the entrance
 *@buff: stores the information entered by the user
 *Return: 0, if there are space and -1, if there are is no
 */
int _spaces(char *buff)
{
	int i = 0;

	while (buff[i] != '\n')
	{
		if (buff[i] != ' ')
			return (0);
		i++;
	}
	return (-1);
}
