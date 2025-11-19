import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def main():
    Task = int(input())
    for _ in range(Task):
        m = int(input())

        l, r = 0, 10_000_000

        while l + 1 < r:
            mid = (l + r) // 2
            t = mid * (mid + 1) * (mid + 2) / 6
            if t <= m:
                l = mid
            else:
                r = mid
        print(r)


main()
