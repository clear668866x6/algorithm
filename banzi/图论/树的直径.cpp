namespace shudezhijing{
    VI g[N];
    int mx[N],idx[N];

    void dfs(int u,int fa){
        idx[u]=u;
        mx[u]=0;
        for(auto& j:g[u]){
            if(j==fa)continue;
            dfs(j,u);
            if(mx[j]+1>mx[u]){
                mx[u]=mx[j]+1;
                idx[u]=idx[j];
            }
        }
    }

    int work(){
        dfs(1,0);

        int rt=idx[1];

        dfs(rt,0);

        return mx[rt];
    }
}