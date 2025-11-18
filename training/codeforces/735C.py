import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def main():
    Task = 1
    for _ in range(Task):
        n = int(input())
        ans = 1
        d1, d2 = 1, 2

        while d1 + d2 <= n:
            ans += 1
            d2, d1 = d1 + d2, d2

        print(ans)


main()
