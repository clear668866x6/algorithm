import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())

    ans = 0

    while True:
        t = n
        p = (t // 10) * 10
        if p == 0:
            ans += n
            break
        n -= p
        n += t // 10
        ans += p
    print(ans)


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
