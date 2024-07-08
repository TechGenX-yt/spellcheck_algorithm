# python version 

import numpy as np

def getDistance(search_input, word):
    a, b = len(search_input), len(word)
    addn_wt, del_wt, subs_wt = 1, 1, 1

    # if search input is incomplete, i.e. a substring of word
    if search_input in word:
        return (b - a) * addn_wt * 0.25

    # initialisation of matrix
    distanceMatrix = np.zeros((a + 1, b + 1), dtype=int)

    # storing non reccursive values
    distanceMatrix[:, 0] = np.arange(a + 1)
    distanceMatrix[0] = np.arange(b + 1)

    # reccursive steps
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            if search_input[i - 1] == word[j - 1]:  # if end charecters match up
                distanceMatrix[i][j] = distanceMatrix[i - 1][j - 1]
            else:
                distanceMatrix[i][j] = min(
                    distanceMatrix[i][j - 1] + addn_wt,
                    distanceMatrix[i - 1][j] + del_wt,
                    distanceMatrix[i - 1][j - 1] + subs_wt
                )

    return distanceMatrix