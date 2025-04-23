namespace dfsxu{
    VI g[N];
    int siz[N];
    int dfn[N],tmd;

    void dfs(int u,int fa){
        dfn[u]=++tmd;
        siz[u]=1;
        for(auto& j:g[u]){
            if(j==fa)continue;
            dfs(j,u);
            siz[u]+=siz[j];
        }
    }
}