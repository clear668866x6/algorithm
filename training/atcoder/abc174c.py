import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())
    t = 0
    for i in range(1, 1000_001):
        t = t * 10 + 7
        if t % n == 0:
            print(i)
            return
        t %= n
    print(-1)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
