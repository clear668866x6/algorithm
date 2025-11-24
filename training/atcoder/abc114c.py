import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())

    mp = set()
    mp2 = Counter()

    a = []

    def dfs(u):
        if a:
            t = 0
            for x in a:
                t = t * 10 + x
                mp2[x] += 1
            if mp2[3] >= 1 and mp2[5] >= 1 and mp2[7] >= 1:
                if t <= n:
                    mp.add(t)
            mp2.clear()
        if u > 10:
            return

        for i in [3, 5, 7]:
            a.append(i)
            dfs(u + 1)
            a.pop()

    dfs(1)

    print(len(mp))


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
