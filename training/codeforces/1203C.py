import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())
    w = list(map(int, input().split()))

    g = 0
    for i in w:
        g = math.gcd(g, i)
    ans = 0
    for i in range(1, int(math.sqrt(g)) + 1):
        if g % i == 0:
            if g / i == i:
                ans += 1
            else:
                ans += 2

    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
