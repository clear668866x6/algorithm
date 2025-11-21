import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())
    w = [list(map(int, input().split())) for _ in range(n)]

    l = max(range(n), key=lambda i: w[i][0])
    r = min(range(n), key=lambda i: w[i][1])

    def calc(k):
        tl, tr = -float("inf"), float("inf")
        for i in range(n):
            if i == k:
                continue
            tl = max(tl, w[i][0])
            tr = min(tr, w[i][1])

        return max(0, tr - tl)

    ans = max(calc(l), calc(r))
    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
