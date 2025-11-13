import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()

INF = math.inf
MOD = 10**9 + 7


def I():
    return input()


def II():
    return int(input())


def MI():
    return map(int, input().split())


def LI():
    return list(input().split())


def LII():
    return list(map(int, input().split()))


def GMI():
    return map(lambda x: int(x) - 1, input().split())


def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))


def debug(*args):
    print("\033[92m", *args, "\033[0m", file=sys.stderr)


def lowbit(x):
    return x & -x


def solve():
    n, l, r, s = MI()
    len = r - l + 1
    mx = (n + n - len + 1) * len // 2
    mn = (1 + len) * len // 2
    if s < mn or s > mx:
        print(-1)
        return

    vis = [0] * (n + 1)
    s -= mn
    ans = [0] * n

    for i in range(l, r + 1):
        ans[i - 1] = i - l + 1

    while s > 0:
        for i in range(r, l - 1, -1):
            ans[i - 1] += 1
            s -= 1
            if s == 0:
                break

    for i in range(1, n + 1):
        vis[ans[i - 1]] = 1

    for i in range(1, n + 1):
        if i >= l and i <= r:
            continue
        for j in range(1, n + 1):
            if vis[j] == 0:
                ans[i - 1] = j
                vis[j] = 1
                break

    print(*ans)


def main():
    Task = 1
    Task = II()
    for _ in range(Task):
        solve()


if __name__ == "__main__":
    main()
