import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def main():
    Task = int(input())
    for _ in range(Task):
        n, a, b = map(int, input().split())
        w = list(map(int, input().split()))

        c0, c1 = 0, 0
        for i in range(n):
            if w[i] & 1:
                c0 += 1
            else:
                c1 += 1

        ans = int(1e18)
        if c0 == 0 or c1 == 0:
            ans = min(ans, (n - 1) * a, (n - 1) * n // 2 * a)
        elif a > 0 and b > 0:
            ans = min(ans, (n - 2) * a + b, (n - 1) * b)
        elif a <= 0 and b > 0:
            ans = min(ans, (c0 - 1) * c0 // 2 * a + (c1 - 1) * c1 // 2 * a + b)
        elif a > 0 and b <= 0:
            ans = min(ans, c0 * c1 * b)
        else:
            ans = min(
                ans, (c0 - 1) * c0 // 2 * a + (c1 - 1) * c1 // 2 * a + c0 * c1 * b
            )
        print(ans)


main()
