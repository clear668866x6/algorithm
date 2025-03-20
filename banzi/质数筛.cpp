namespace shai{
    int primes[N],cnt;
    bool vis[N];
    int phi[N];

    void init(int x){
        phi[1]=1;
        FOR(i,2,x){
            if(!vis[i])primes[cnt++]=i,phi[i]=i-1;
            for(int j=0;i*primes[j]<=x;j++){
                vis[i*primes[j]]=1;
                if(i%primes[j]==0){
                    phi[i*primes[j]]=phi[i]*primes[j];
                    break;
                }
                phi[i*primes[j]]=phi[i]*(primes[j]-1);
            }
        }
    }
}