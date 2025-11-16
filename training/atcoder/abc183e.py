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
        n, m = map(int, input().split())
        s = [input() for _ in range(n)]

        f = [[0] * (m + 1) for _ in range(n + 1)]
        a = [[0] * (m + 1) for _ in range(n + 1)]
        b = [[0] * (m + 1) for _ in range(n + 1)]
        c = [[0] * (m + 1) for _ in range(n + 1)]

        f[1][1] = 1

        mod = 10**9 + 7

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if i == 1 and j == 1:
                    continue
                if s[i - 1][j - 1] == "#":
                    continue
                a[i][j] = a[i - 1][j] + f[i - 1][j]
                b[i][j] = b[i][j - 1] + f[i][j - 1]
                c[i][j] = c[i - 1][j - 1] + f[i - 1][j - 1]
                f[i][j] += a[i][j] + b[i][j] + c[i][j]
                f[i][j] %= mod

        print(f[n][m])


main()
