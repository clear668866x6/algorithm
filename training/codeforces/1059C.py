import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def main():
    Task = 1
    for _ in range(Task):
        n = int(input())
        t = 1
        ans = []
        while n > 3:
            for i in range((n + 1) // 2):
                ans.append(t)
            t *= 2
            n //= 2

        ans = ans + [t] * (n - 1) + [t * n]
        print(" ".join(map(str, ans)))


main()
