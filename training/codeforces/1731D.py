import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n, m = map(int, input().split())

    w = [list(map(int, input().split())) for _ in range(1, n + 1)]

    s = [[0] * (m + 1) for _ in range(1, n + 2)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            s[i][j] = w[i - 1][j - 1]

    l, r = 0, min(n, m) + 1

    def check(x):
        t = [[0] * (m + 1) for _ in range(1, n + 2)]

        def calc(x1, y1, x2, y2):
            return t[x2][y2] - t[x1 - 1][y2] - t[x2][y1 - 1] + t[x1 - 1][y1 - 1]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                t[i][j] = (s[i][j] - x) >= 0

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                t[i][j] += t[i - 1][j]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                t[i][j] += t[i][j - 1]

        for i in range(x, n + 1):
            for j in range(x, m + 1):
                p = calc(i - x + 1, j - x + 1, i, j)
                if p == x * x:
                    return 1

        return 0

    while l + 1 < r:
        mid = (l + r) // 2
        if check(mid):
            l = mid
        else:
            r = mid

    print(l)


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
