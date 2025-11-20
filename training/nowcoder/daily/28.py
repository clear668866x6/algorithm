import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n, c = map(int, input().split())

    ans = 0
    lenc = len(str(c))

    for a in range(c + 1):
        b = c - a
        lena, lenb = len(str(a)), len(str(b))
        if lena + lenb + 2 + lenc == n:
            ans += 1

    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
