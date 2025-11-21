import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())

    l, r = 0, int(1e9)

    while l + 1 < r:
        mid = (l + r) // 2
        t = mid * (mid + 1) * (mid + 2) // 6
        if t <= n:
            l = mid
        else:
            r = mid

    print(r)


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
