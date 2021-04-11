#include "header_file.h"

char *_strtok(char *s, char *delim)
{
	int i = 0, j = 0;
	char *p = NULL;
	static int e = 0;

	p = malloc(sizeof(char) * 512);
	if (p == NULL)
		return (NULL);
	for (i = e; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == delim[0])
			continue;
		else
		{
			p[j] = s[i];
			if (s[i + 1] == ' '|| s[i + 1]=='\n' || s[i + 1]=='\t' || s[i + 1] == delim[0])
			{
				p[j + 1] = ' ';
				j++;
			}
			j++;
		}
	}
	p[j] = '\0';
	e = i;
	return (p);
}