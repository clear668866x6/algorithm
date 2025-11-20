import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


sys.setrecursionlimit(10**9)


def solve():
    n, q = map(int, input().split())
    g = [[] for _ in range(n + 1)]

    for i in range(n - 1):
        a, b = map(int, input().split())
        g[a].append(b)
        g[b].append(a)

    w = [0] * (n + 1)

    for i in range(q):
        a, b = map(int, input().split())
        w[a] += b

    ans = [0] * (n + 1)
    vis = [0] * (n + 1)

    q = deque()
    q.append((1, 0, 0))

    while len(q):
        t, u, tot = q.pop()

        if vis[t]:
            continue
        vis[t] = 1

        nw = tot + w[t]
        ans[t] = nw

        for j in g[t]:
            if j != u:
                q.append((j, u, nw))

    print(*ans[1:])


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
