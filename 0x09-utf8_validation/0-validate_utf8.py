#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    :type data: List[int]
    :rtype: True if data is a valid UTF-8 encoding, else return False.
    """
    numberOfBytes = 0

    # Check if the 8th bit from the left is set or not
    mask1 = 1 << 7
    # Check if the 7th bit from the left is set or not
    mask2 = 1 << 6

    for number in data:
        mask = 1 << 7
        if numberOfBytes == 0:
            while mask & number:
                numberOfBytes += 1
                mask = mask >> 1

            if numberOfBytes == 0:
                continue

            if numberOfBytes == 1 or numberOfBytes > 4:
                return False
        else:
            if not (number & mask1 and not (number & mask2)):
                return False

        numberOfBytes -= 1
    if (numberOfBytes == 0):
        return True
    else:
        return False
