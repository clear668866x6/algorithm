namespace LCA{
    int siz[N],dep[N],f[22][N],dfn[N],tmd;
    vector<int> g[N];

    int pd(int x,int y){
        return dfn[x]<dfn[y]?x:y;
    }

    void dfs(int u,int fa){
        f[0][dfn[u]=++tmd]=fa;
        for(auto& j:g[u]){
            if(j==fa)continue;
            dfs(j,u);
        }
    }

    int lca(int x,int y){
        if(x==y)return x;
        if((x=dfn[x])>(y=dfn[y]))swap(x,y);
        int d=__lg(y-x++);
        return pd(f[d][x],f[d][y-(1<<d)+1]);
    }

    void init(int rt,int n){
        dfs(rt,0);

        FOR(i,1,__lg(n)){
            for(int j=1;j+(1<<i)-1<=n;j++){
                f[i][j]=pd(f[i-1][j],f[i-1][j+(1<<i-1)]);
            }
        }
    }
}