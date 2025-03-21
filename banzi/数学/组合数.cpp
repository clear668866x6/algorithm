namespace comb{
    int fac[N],infac[N];

    int qmi(int a,int b){
        int res=1;
        while(b){
            if(b&1)res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    }

    void init(int x){
        fac[0]=infac[0]=1;
        FOR(i,1,x){
            fac[i]=fac[i-1]*i%mod;
        }
        infac[x]=qmi(fac[x],mod-2);

        FORD(i,0,x-1){
            infac[i]=infac[i+1]*(i+1)%mod;
        }
    }

    int A(int x,int y){
        if(x<y||x<0||y<0)return 0;
        return fac[x]*infac[x-y]%mod;
    }

    int C(int x,int y){
        if(x<y||x<0||y<0)return 0;
        return fac[x]*infac[y]%mod*infac[x-y]%mod;
    }
}