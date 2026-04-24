#!/usr/bin/python3
"""Minimum operations module."""


def minOperations(n):
    """Calculate the fewest operations needed to get exactly n H chars."""
    if not isinstance(n, int) or n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
