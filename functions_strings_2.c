#include "header_file.h"

/**
 * _strcat - Entry point
 * @src: source
 * @dest: dest
 * Return: -
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, counter = 0;

	for ( ; dest[i] != '\0'; i++)
		counter++;
	for ( ; src[j] != '\0'; j++)
		dest[counter + j] = src[j];
	dest[counter + j] = '\0';
	return (dest);
}

/**
 * _itoa - function that change a integer to string
 * @number: integer to convert
 * Return: a string with of integer
 */
char *_itoa(int number)
{
	int i, j, k, h;
	char *s, *str;

	s = _calloc(512, sizeof(char));
	for (i = 0 ; number > 0 ; i++)
	{
		s[i] = (number % 10) + '0';
		number = (number / 10);
	}
	s[i] = '\0';
	j = _strlen(s);
	h = j;
	h--;
	str = _calloc(j + 1, sizeof(char));
	for (k = 0; k < j ; k++)
	{
		str[k] = s[h];
		h--;
	}
	free(s);
	str[k] = '\0';
	return(str);
}