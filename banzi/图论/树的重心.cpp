namespace Treecore{
    VI g[N];
    int siz[N];

    void dfs(int u,int fa){
        siz[u]=1;
        int mx=0;
        for(auto& j:g[u]){
            if(j==fa)continue;
            dfs(j,u);
            siz[u]+=siz[j];
            mx=max(mx,siz[j]);
        }
        mx=max(mx,n-siz[u]);
        if(mx<=n/2){
            cout<<u<<' ';
            exit(0);
        }
    }
}