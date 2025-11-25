import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n, k = map(int, input().split())

    ans = 0

    for a in range(1, n + 1):
        if (a * 2) % k == 0:
            p = (k - a % k) % k
            t = (n + p) // k
            ans += t * t

    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
