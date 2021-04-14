#include "header_file.h"

/**
 *_strlen - counter of character
 *@s: string
 *Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0, c = 0;

	for ( ; s[i] != '\0' ; i++)
		c++;
	return (c);
}

/**
 *_strcpy - Copy string for destination
 *@dest: destination variable
 *@src: source variable
 *Return: string of destination that is, the copy
 */
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

/**
 *_strchr - function locates the first occurrence of character
 *@s: string to be examined
 *@c: character to find
 *Return: a pointer to the character c
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	if (s[i] == c)
		return (&s[i]);
	return ('\0');
}

/**
 * _strncmp - compare the first n bytes of the string
 * @s1: first string to be compared
 * @s2: second string to be compared
 * @n_bytes: maximum number of characters to compare
 * Return: length of the string
 */
int _strncmp(char *s1, char *s2, size_t n_bytes)
{
	size_t i = 0, j = 0;

	while (i < n_bytes)
	{
		if (s1[i] != s2[i])
		{
			j = (s1[i] - s2[i]);
			break;
		}
		else
			j = (0);
		i++;
	}
	return (j);
}

/**
 *_strcmp - compare two strings
 *@s1: string one
 *@s2: string two
 *Return: if s1 and s2 are equal, returns 0
 */
int _strcmp(char *s1, char *s2)
{
	int q;

	if (_strlen(s1) == _strlen(s2))
	{
		for (q = 0; s1[q] && s2[q] != '\0'; q++)
			if (s1[q] != s2[q])
				return (s1[q] - s2[q]);
		return (0);
	}
	else if (_strlen(s1) > _strlen(s2))
		return (1);
	return (-1);
}
