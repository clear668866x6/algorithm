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
        n, m = map(int, input().split())
        g = [[] for _ in range(n)]
        d = [0] * n

        for _ in range(m):
            a, b = map(int, input().split())
            if a > b:
                a, b = b, a
            a -= 1
            b -= 1
            g[a].append(b)
            g[b].append(a)
            d[a] += 1
            d[b] += 1

        f = [1] * n

        for i in range(n):
            for j in g[i]:
                if j > i:
                    f[j] = max(f[j], f[i] + 1)

        print(max(x * y for x, y in zip(f, d)))


main()
