namespace LCA{
    VI g[N];
    int dep[N];
    int f[N][22];

    void dfs(int u,int fa){
        dep[u]=dep[fa]+1;
        f[u][0]=fa;

        FOR(i,1,20)f[u][i]=f[f[u][i-1]][i-1];

        for(auto& j:g[u]){
            if(j==fa)continue;
            dfs(j,u);
        }
    }

    int lca(int x,int y){
        if(dep[x]<dep[y])swap(x,y);

        FORD(i,1,20){
            if(dep[f[x][i]]>=dep[y]){
                x=f[x][i];
            }
        }
        if(x==y)return x;

        FORD(i,1,20){
            if(f[x][i]!=f[y][i]){
                x=f[x][i];
                y=f[y][i];
            }
        }
        return f[x][0];
    }
}