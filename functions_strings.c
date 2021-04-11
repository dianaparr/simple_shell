#include "header_file.h"

int _strlen(char *s)
{
	int i = 0, c = 0;

	for ( ; s[i] != '\0' ; i++)
		c++;
	return (c);
}

char *_strcpy(char *dest, char *src)
{
	int len = 0;

	for ( ; src[len] != '\0'; len++)
	{
		dest[len] = src[len];
	}
	dest[len] = 0;
	return (dest);
}