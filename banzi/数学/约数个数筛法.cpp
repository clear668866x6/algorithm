namespace cntyue{
    int primes[N],cnt;
    bool vis[N];
    int f[N],g[N];//g[x] 表示x的最小质因数的个数,d[x]表示x的约数个数

    void init(int x){
        f[1]=1;
        FOR(i,2,x){
            if(!vis[i])primes[cnt++]=i,f[i]=2,g[i]=1;
            for(int j=0;i*primes[j]<=x;j++){
                vis[i*primes[j]]=1;
                if(i%primes[j]==0){
                    g[i*primes[j]]=g[i]+1;
                    f[i*primes[j]]=f[i]/(g[i]+1)*(g[i]+2);
                    break;
                }
                g[i*primes[j]]=1;
                f[i*primes[j]]=f[i]*2;
            }
        }
    }
}