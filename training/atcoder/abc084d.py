import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def main():
    Task = int(input())
    mx = 10**5
    f = [0] * (mx + 10)
    c = 0

    t = [0] * (mx + 10)

    for i in range(2, mx + 1):
        p1 = 1
        p2 = 1

        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                p1 = 0
                break
        t = (i + 1) // 2
        for j in range(2, int(math.sqrt(t)) + 1):
            if t % j == 0:
                p2 = 0
                break
        if p1 and p2 and t != 1:
            c += 1
        f[i] = c

    for _ in range(Task):
        l, r = map(int, input().split())

        ans = f[r] - f[l - 1]
        print(ans)


main()
