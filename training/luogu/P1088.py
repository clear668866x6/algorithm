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
        m = int(input())
        w = list(map(int, input().split()))
        p = []
        p = list(permutations(w))[m]
        print(*p)


main()
