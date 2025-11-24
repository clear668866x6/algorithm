import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()

mod = int(1e9 + 7)
N = int(1e5 + 10)


def qmi(a, b):
    ans = 1
    while b:
        if b % 2 == 1:
            ans = ans * a % mod
        a = a * a % mod
        b /= 2
    return ans


fac, infac = [0] * (N), [0] * (N)


def init():
    n = N - 10
    fac[0] = 1
    for i in range(1, n + 1):
        fac[i] = fac[i - 1] * i % mod
    infac[n] = qmi(fac[n], mod - 2)

    for i in range(n - 1, -1, -1):
        infac[i] = infac[i + 1] * (i + 1) % mod


def C(x, y):
    return fac[x] * infac[y] % mod * infac[x - y] % mod


def solve():
    n, m = map(int, input().split())
    w = list(map(int, input().split()))

    w.sort()

    init()

    print(C(2, 1), qmi(3, 2))

    ans = 0

    for i in range(m - 1, n):
        ans += C(i, m - 1) * w[i]
        ans %= mod

    for i in range(n - m):
        ans -= C(n - i + 1, m - 1) * w[i]
        ans %= mod
    print(ans)


def main():
    Task = 1
    for _ in range(Task):
        solve()


main()
