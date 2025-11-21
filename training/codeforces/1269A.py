import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def solve():
    n = int(input())
    a = list(map(int, input().split()))

    s = sum(a)

    mp = Counter()
    mp2 = Counter()

    if s & 1:
        print("YES")
    else:
        for x in a:
            if x & 1:
                mp[x] += 1
            else:
                mp2[x] += 1

        if len(mp) and len(mp2):
            print("YES")
        else:
            print("NO")


def main():
    Task = int(input())
    for _ in range(Task):
        solve()


main()
