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

    currentTotal = 0
    currentCoin = 0
    totalAmountCoins = 0

    coins.sort(reverse=True)

    for coin in coins:
        currentCoin = int((total - currentTotal) / coin)
        currentTotal += currentCoin * coin
        totalAmountCoins += currentCoin

    if total - currentTotal > 0:
        return -1

    return totalAmountCoins
