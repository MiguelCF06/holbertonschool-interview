#!/usr/bin/python3
"""
Check for minimum operations of Copy all and paste in a file.
"""


def minOperations(n):
    """Minimum number of operations needed to result in exactly
    n H characters. Operations: CopyAll and Paste"""
    if (n < 2 or type(n) is not int):
        return 0

    actualValue = 1
    operations = 0

    while (actualValue != n):
        if (n % actualValue == 0):
            copy = actualValue
            paste = actualValue + copy
            operations += 2

        else:
            paste = actualValue + copy
            operations += 1

        actualValue = paste

    return operations
