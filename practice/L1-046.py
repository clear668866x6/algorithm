n=int(input())

ans=1
tot=1

while True:
    if ans%n==0:
        print("%d" %(ans//n),tot,sep=" ")
        break
    ans=ans*10+1
    tot+=1

