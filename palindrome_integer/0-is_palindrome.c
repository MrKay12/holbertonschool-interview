#include "palindrome.h"

/**
 * is_palindrome - checks whether an unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long original;
    unsigned long reverse;

    original = n;
    reverse = 0;

    while (n > 0)
    {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }

    return (reverse == original);
}