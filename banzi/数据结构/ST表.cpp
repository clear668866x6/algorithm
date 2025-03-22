namespace ST{
    int f[N][22],w[N];

    void init(int n){
        FOR(j,0,20){
            for(int i=1;i+(1<<j)-1<=n;i++){
                if(!j)f[i][j]=w[i];
                else f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
            }
        }
    }

    int query(int l,int r){
        int len=__lg(r-l+1);
        return min(f[l][len],f[r-(1<<len)+1][len]);
    }
}