import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    a, b, x, y = map(int, input().split())

    ans = math.inf

    for i in range(30):
        for j in range(30):
            for k in range(30):
                if a - i * x - k * y <= 0 and b - j * x - k * y <= 0:
                    ans = min(ans, i + j + k)

    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
