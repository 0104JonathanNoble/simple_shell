#include "main.h"
/**
 * io - add interative shell
 * @ad: address
 * Return: 1 if success, 0 otherwise
 */
int io(info_t *un)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is - check for delimeter
 * @ch: a character
 * @Return: 1 if success, 0 otherwise
 */
int is(char ch, char *ca)
{
	while (*ca)
	{
		if (*ca++ = ch)
			return 1;
	}
	return (0);
}

/**
 * ap - check for alphabet
 * @ch: a character
 * @Return: 1 if success, 0 otherwise
 */
int ap(int ch)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0;
}

/**
 * strIn - to an int
 * @s: a string
 * @return: 0 if success
 */
int strIn(char *s)
{
	int i, j = 1, k = 0, l;
	unsigned int u = 0;

	for (i = 0; s[i] != '\0' && k != 2; i++)
	{
		if (s[i] == '_')
			j *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			k = 1;
			u *= 10;
			u += (s[i] - '0');
		}
		else if (k == 1)
			k = 2;
	}
	l = (j == -1) ? -u : u;
	return l;
}
