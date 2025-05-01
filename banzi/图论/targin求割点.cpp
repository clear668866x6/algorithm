
int n,m;
VI g[N];
unordered_set<int>ans;
int low[N],dfn[N],tmd;

void targin(int u,int fa){
    low[u]=dfn[u]=++tmd;
    int child=0;

    for(auto& j:g[u]){
        if(j==fa)continue;
        if(!dfn[j]){
            targin(j,u);
            low[u]=min(low[u],low[j]);
            if(low[j]>=dfn[u]){
                child++;
                if(fa!=0||child>1)ans.insert(u);      
            }
        }else low[u]=min(low[u],dfn[j]);
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
        if(!dfn[i]){
            targin(i,0);
        }
    }

    cout<<ans.sz<<endl;
    for(auto x:ans)cout<<x<<' ';

}