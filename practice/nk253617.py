def solve():
    n=int(input())
    w=[0]*(n+1)
    f=[0]*(n+1)
    t=list(map(int,input().split()))
    for i in range(0,n):
        w[i+1]=t[i]
    for i in range(1,n+1):
        f[i]=max(f[i-1]+w[i],f[i-1]*w[i])
        if f[i]>998244353:
            f[i]=f[i]%998244353+998244353
    
    print(f[n]%998244353)


if __name__ =="__main__":
    T=int(input())
    for i in range(0,T):
        solve()