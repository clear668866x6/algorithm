namespace Division{
    //针对单点修改，路径查询操作

    int son[N],dfn[N],tmd,top[N];
    int fat[N],siz[N];
    VI g[N];
    int tr[N<<2],dep[N];

    void modify(int u,int v){
        for(tr[u+=n]=v;u>1;u>>=1)tr[u]=max(tr[u],tr[u^1]);
    }

    int query(int l,int r){
        int res=0;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1)res=max(res,tr[l++]);
            if(r&1)res=max(res,tr[--r]);
        }
        return res;
    }

    void dfs1(int u,int fa){
        dep[u]=dep[fa]+1;
        fat[u]=fa;
        siz[u]=1;
        for(auto& j:g[u]){
            if(j==fa)continue;
            dfs1(j,u);
            siz[u]+=siz[j];
            if(siz[son[u]]<siz[j])son[u]=j;
        }
    }

    void dfs2(int u,int t){
        dfn[u]=++tmd,top[u]=t;
        if(son[u])dfs2(son[u],t);

        for(auto& j:g[u]){
            if(j==fat[u]||j==son[u])continue;
            dfs2(j,j);
        }
    }

    int query_path(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans=max(ans,query(dfn[top[x]],dfn[x]+1));
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        ans=max(ans,query(dfn[x],dfn[y]+1));
        return ans;
    }
}