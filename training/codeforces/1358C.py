import sys
import math
from collections import defaultdict, deque, Counter
from heapq import *
from itertools import accumulate, combinations, permutations
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().strip()


def main():
    Task = int(input())
    for _ in range(Task):
        x1, y1, x2, y2 = map(int, input().split())
        print((x2 - x1) * (y2 - y1) + 1)


main()
