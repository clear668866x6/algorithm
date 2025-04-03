def solve(n, k):
    if n == 0:
        return []
    if k < n:
        a = [-1 for i in range(n)]
        if k > 0:
            a[k - 1] = 200
        a[k] = -400
    else:
        a = solve(n - 1, k - n)
        a.append(1000)
    return a

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    b = solve(n, k)
    print(*b)