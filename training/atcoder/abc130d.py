import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n, k = map(int, input().split())
    w = list(map(int, input().split()))

    pre = [0]

    for i in range(n):
        pre.append(pre[-1] + w[i])

    ans = 0

    for i in range(n):
        t = bisect_left(pre, pre[i] + k)
        ans += max(0, n - t + 1)

    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
