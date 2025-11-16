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
        w = list(map(int, input().split()))

        g = math.gcd(*w)

        for i in range(n):
            w[i] //= g

        mx = max(w)
        fac = list(range(mx + 1))
        for i in range(2, mx + 1):
            if i == fac[i]:
                for j in range(i, mx + 1, i):
                    fac[j] = i

        vis = [0] * (mx + 1)

        for x in w:
            while x > 1:
                t = fac[x]
                if vis[t]:
                    print("NO")
                    return
                vis[t] += 1
                while x % t == 0:
                    x //= t
    print("YES")


main()
