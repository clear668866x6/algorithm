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

    f = [int(1e18)] * (n + 2)

    mex = 0
    mp = Counter()
    for x in w:
        mp[x] += 1
        while mp[mex]:
            mex += 1

    f[mex] = 0
    for i in range(mex + 1, -1, -1):
        for j in range(i):
            f[j] = min(f[j], f[i] + i * (mp[j] - 1) + j)

    print(f[0])


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
