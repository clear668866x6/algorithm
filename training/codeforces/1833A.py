import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())
    s = input()

    mp = defaultdict(int)

    for i in range(n - 1):
        p = s[i : i + 2]
        mp[p] += 1

    print(len(mp))


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
