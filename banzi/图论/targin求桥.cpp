
int n,m;
VI g[N];
VPII ans;
int low[N],dfn[N];
int tmd;

void targin(int u,int fa){
    low[u]=dfn[u]=++tmd;

    for(auto& j:g[u]){
        if(!dfn[j]){
            targin(j,u);
            low[u]=min(low[u],low[j]);
            if(low[j]>dfn[u]){
                ans.pb({u,j});
            }
        }else if(j!=fa){
            low[u]=min(low[u],dfn[j]);
        }
    }
}

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    FOR(i,1,n){
        if(!dfn[i])targin(i,0);
    }

    cout<<ans.sz<<endl;
    for(auto [x,y]:ans)cout<<x<<' '<<y<<endl;

}