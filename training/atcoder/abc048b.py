import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    a, b, x = map(int, input().split())
    print(b // x - (a - 1) // x)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
