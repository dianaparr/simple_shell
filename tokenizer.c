#include "header_file.h"

/**
 *_strtok_v2 - function that tokenizes a complete string
 *@s: buff of the getline
 *@delim: separator of words
 *Return: the buff tokenized
 */
char *_strtok_v2(char *s, char *delim)
{
	int i = 0, j = 0;
	char *p = NULL;

	p = _calloc(3000, sizeof(char));
	if (p == NULL)
		return (NULL);
	for ( ; s[i] != '\0'; i++)
	{
		if (s[i] == delim[0] || s[i] == '\n')
			continue;
		else
		{
		p[j] = s[i];
		if (s[i + 1] == delim[0])
			p[j + 1] = ' ',
			j++;
		j++;
		}
	}
	if (p[j - 1] == 32)
		p[j - 1] = 0;
	else
		p[j] = '\0';
	return (p);
}
