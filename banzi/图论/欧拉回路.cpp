namespace UriCircle{
    set<int>g[N];
    VI ans;
    int n;

    void dfs(int u){
        while(g[u].sz){
            int now=*g[u].begin();
            g[now].erase(u);
            g[u].erase(now);
            dfs(now);
        }
        ans.pb(u);
    }

    bool isuri(){
        FOR(i,1,n){
            if(g[u].sz%2){
                return false;
            }
        }
        return true;
    }
}