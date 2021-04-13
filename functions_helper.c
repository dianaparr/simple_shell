#include "header_file.h"

char **alloc_double_pointer(int count_wds, char *buff, char *delim)
{
	char **buff_two, *p = NULL;
	int i = 0;
	
	buff_two = malloc((count_wds + 1) * sizeof(char *));
	if (buff_two == NULL)
		return (NULL);
	for ( ; i < count_wds; i++)
	{
		/* *buff_two = NULL; */
		if (i == 0)
			p = strtok(buff, delim);
		else
			p = strtok(NULL, delim);
		buff_two[i] = p;
	}
	buff_two[i] = NULL;
	return (buff_two);
}

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
	unsigned int i;
	char *mem_arr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem_arr = malloc(nmemb * size);
	if (mem_arr == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		mem_arr[i] = 0;
	return (mem_arr);
}

char *_getenv(const char *name)
{
	int i = 0;
	unsigned int len = 0;
	char *value = NULL, *address = NULL;

	len = _strlen((char *)name);
	for ( ; environ[i] != NULL; i++)
	{
		address = environ[i];
		value = _strchr(address, '=');
		if (value && (((value - address) == len) && !_strncmp(address, (char *)name, len)))
			return (value + 1);
	}
	return (NULL);
}
