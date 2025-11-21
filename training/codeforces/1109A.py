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

    pre = [0] * (n + 1)

    mp, mp2 = Counter(), Counter()
    mp2[0] = 1
    ans = 0

    for i in range(1, n + 1):
        pre[i] = pre[i - 1] ^ w[i - 1]
        if i & 1:
            ans += mp[pre[i]]
            mp[pre[i]] += 1
        else:
            ans += mp2[pre[i]]
            mp2[pre[i]] += 1

    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
