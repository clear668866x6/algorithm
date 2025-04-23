namespace dianfenTree{
    int siz[N],k,rt,mx[N],tot,cnt;
    bool vis[N];
    PII p[N];
    VI g[N];
    int ans;

    void dfs(int u,int fa){
        siz[u]=1;
        mx[u]=0;
        for(auto& j:g[u]){
            if(j==fa||vis[j])continue;
            dfs(j,u);
            siz[u]+=siz[j];
            mx[u]=max(mx[u],siz[j]);
        }
        mx[u]=max(mx[u],n-siz[u]);
        if(mx[u]<mx[rt])rt=u;
    }

    void dfs2(int u,int fa,int a,int b){
        if(b>k||a>k)RE;
        p[++cnt]={a,b};
        for(auto j:g[u]){
            if(j==fa||vis[j])continue;
            dfs2(j,u,a+1,b+1);
        }
    }

    void calc(int x,int s){
        tot=s;
        rt=0;
        dfs(x,x);
        vis[rt]=1;
        set<PII>st;
        st.insert({0,0});
    
        for(auto& j:g[rt]){
            if(vis[j])continue;
            cnt=0;
            dfs2(j,rt,1,1);
            for(int i=1;i<=cnt;i++){
                auto it=st.lower_bound({k-p[i].fi,0});
                if(it!=st.end()&&it->first+p[i].fi==k){
                    ans++;
                }
            }
            for(int i=1;i<=cnt;i++)st.insert(p[i]);
        }
        st.clear();
    
        for(auto& j:g[rt]){
            if(vis[j])continue;
            calc(j,siz[j]);
        }
    }

}