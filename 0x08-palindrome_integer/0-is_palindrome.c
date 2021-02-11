#include "palindrome.h"
/**
 * is_palindrome - Checks wheter or not a given integer is a palindrome
 * @n: The unsigned integer to check
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversedN = 0, originalN, remainder;

	originalN = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversedN = reversedN * 10 + remainder;
		n /= 10;
	}

	if (originalN == reversedN)
		return (1);
	else
		return (0);
}
