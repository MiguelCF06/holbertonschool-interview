#!/usr/bin/python3
import sys
"""
Determine the fewest number of coins to meet a given amount
"""


def makeChange(coins, total):
    '''
    :@param coins: The coins that we have to exchange
    :@param total: The given amount to meet
    :return: The fewest number of coins to meet the total
    '''

    if total <= 0:
        return 0

    coins.sort(reverse=True)

    remaining = total
    i = 0
    amount_coins = 0

    while (i < len(coins)):
        if remaining == 0:
            return amount_coins

        if coins[i] > remaining:
            i += 1
        else:
            remaining -= coins[i]
            amount_coins += 1

    return -1
