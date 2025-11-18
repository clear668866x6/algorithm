import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def main():
    Task = 1
    for _ in range(Task):
        n = int(input())
        s = input()
        w = list(map(int, input().split()))

        s = " " + s
        t = " hard"

        f = [[1e18] * 5 for _ in range(n + 1)]

        for _ in range(1, 5):
            f[0][_] = 0

        for i in range(1, n + 1):
            for j in range(1, 5):
                if s[i] == t[j]:
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j] + w[i - 1])
                else:
                    f[i][j] = min(f[i - 1][j - 1], f[i - 1][j])

        print(min(f[n]))


main()
