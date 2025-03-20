if __name__=='__main__':
    n=int(input())
    w=list(map(int,input().split()))
    k=set(w)

    a=sorted(list(k),reverse=True)

    t=a[1] if len(a)>1 else a[0]

    print(t)