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
        n, k = map(int, input().split())

        a = list(map(int, input().split()))

        f = [[0] * 2 for _ in range(n + 1)]

        for i in range(n + 1):
            for j in range(k):
                if i - a[j] >= 0:
                    f[i][0] = max(f[i][0], f[i - a[j]][1] + a[j])
                f[i][1] = i - f[i][0]
        print(f[n][0])


main()
