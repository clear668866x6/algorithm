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
    n, m = MI()

    s = [n + 2, [m + 2, 0]]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            s[i][j] = I()

    print(s)


def main():
    Task = 1
    for _ in range(Task):
        solve()


if __name__ == "__main__":
    main()
