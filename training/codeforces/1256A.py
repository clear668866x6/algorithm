import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    a, b, n, s = map(int, input().split())

    t = min(a, s // n) * n
    d = s - t
    if d > b:
        print("NO")
    else:
        print("YES")


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
