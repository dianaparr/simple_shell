#include "header_file.h"

char **alloc_double_pointer(int count_wds, char *buff, char *delim)
{
	char **buff_two = NULL, *p = NULL;
	int i = 0, len = 0;
	
	len = _strlen(buff);
	buff_two = calloc(len, sizeof(char *));
	if (buff_two == NULL)
		return (NULL);
	for ( ; i < count_wds; i++)
	{
		if (i == 0)
			p = strtok(buff, delim);
		else
			p = strtok(0, delim);
		buff_two[i] = p;
	}
	buff_two[i + 1] = NULL;
	return (buff_two);
}

int _words(char *buff)
{
    int separator = 0, i = 0;
    unsigned number_w = 0;

    for ( ; buff[i] != '\0'; i++)
    {
        if (buff[i] == ' ' || buff[i] == '\n' || buff[i] == '\t' || buff[i] == ':')
            separator = 0;
        else if (separator == 0)
        {
            separator = 1;
            number_w++;
        }
    }
    return number_w;
}

void free_double_pointer(char **buff, int count_wds)
{
	int i = 0;

	for ( ; i < count_wds ; i++)
	{
		free(buff[i]);
	}
	free(buff);
}