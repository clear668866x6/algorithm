namespace Matrix{
    struct E{
        int n,m;
        int x[N][N];
    }A;

    E operator*(const E& a,const E& b){
        E res;
        res.n=a.n,res.m=b.m;
        memset(res.x,0,sizeof res.x);
        FOR(i,0,res.n-1){
            FOR(j,0,res.m-1){
                FOR(k,0,a.m-1){
                    res.x[i][j]=(res.x[i][j]+a.x[i][k]*b.x[k][j]%mod)%mod;
                }
            }
        }
        return res;
    }

    E qmi(E a,int b){
        E res=a;
        b--;
        while(b){
            if(b&1)res=res*a;
            a=a*a;
            b>>=1;
        }
        return res;
    }
}