import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())
    w = list(map(int, input().split()))

    w = [0] + w
    idx = 0
    i = 1
    while i <= n:
        mn = int(1e18)
        for j in range(i, n + 1):
            mn = min(mn, w[j])

        p = []
        for j in range(i, n + 1):
            if mn == w[j]:
                idx = j
                p.append(w[j])
                break

        for j in range(i, idx):
            p.append(w[j])

        for j in range(i, idx + 1):
            w[j] = p[j - i]

        if i != idx:
            i = idx
        else:
            i += 1

    print(*w[1:])


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
