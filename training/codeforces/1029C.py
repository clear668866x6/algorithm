import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())
    w = [[] for _ in range(n)]

    ansl, ansr = -math.inf, math.inf

    mpl, mpr = Counter(), Counter()

    for i in range(n):
        l, r = map(int, input().split())
        ansl = max(ansl, l)
        ansr = min(ansr, r)
        mpl[l] += 1
        mpr[r] += 1
        w[i].append((l, r))

    if mpl[ansl] >= 2 and mpr[ansr] >= 2:
        print(max(0, ansr - ansl))
    elif mpl[ansl] >= 2:
        tl, tr = -math.inf, math.inf
        for i in range(n):
            (l, r) = w[i][0]
            if r == ansr:
                continue
            tl = max(tl, l)
            tr = min(tr, r)
        print(max(0, tr - tl))
    elif mpr[ansr] >= 2:
        tl, tr = -math.inf, math.inf
        for i in range(n):
            (l, r) = w[i][0]
            if l == ansl:
                continue
            tl = max(tl, l)
            tr = min(tr, r)

        print(max(0, tr - tl))
    else:
        tl, tr = -math.inf, math.inf
        for i in range(n):
            (l, r) = w[i][0]
            if l == ansl:
                continue
            tl = max(tl, l)
            tr = min(tr, r)
        ans1 = ansr - ansl
        ans1 = max(ans1, tr - tl)
        tl, tr = -math.inf, math.inf
        for i in range(n):
            (l, r) = w[i][0]
            if r == ansr:
                continue
            tl = max(tl, l)
            tr = min(tr, r)
        ans1 = max(ans1, tr - tl)
        ans1 = max(0, ans1)
        print(ans1)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
