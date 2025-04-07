namespace Bellom-ford{
    int n,m;
    int d[N];
    vector<int>g[N],f[N];
    bool vis[N],vis2[N];
    
    void dfs(int u){
    if(vis[u])RE;
    vis[u]=1;
    for(auto& j:g[u]){
        dfs(j);
    }
    }
    
    void dfs2(int u){
    if(vis2[u])RE;
    vis2[u]=1;
    for(auto& j:f[u]){
        dfs2(j);
    }
    }
    
    void solve() {
    cin>>n>>m;
    
    FOR(i,2,n)d[i]=1e18;
    
    vector<array<int,3>>e;
    
    FOR(i,1,m){
        int a,b,c;
        cin>>a>>b>>c;
        e.pb({a,b,-c});
        g[a].emplace_back(b);
        f[b].emplace_back(a);
    }
    
    dfs(1);
    dfs2(n);
    
    FOR(i,1,n){
        for(auto [a,b,w]:e){//bellom-flord
            if(d[b]>d[a]+w){
                d[b]=d[a]+w;
                if(i==n&&vis[b]&&vis2[a]){
                    cout<<-1<<endl;
                    RE;
                }
            }
        }
    }
    
    cout<<-d[n];
    
    }
    
}