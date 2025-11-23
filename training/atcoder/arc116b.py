import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()

mod = 998244353


def solve():
    n = int(input())
    w = list(map(int, input().split()))

    w.sort()

    ans = 0
    tot = 0
    for i in range(n - 1, -1, -1):
        ans += w[i] * w[i]
        ans %= mod
        ans += w[i] * tot
        ans %= mod
        tot *= 2
        tot += w[i]
        tot %= mod

    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
