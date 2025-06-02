
void solve() {
    int n,m;
    cin>>n>>m;
    n++;
    int ans=0,mod=998244353;

    FOR(i,0,63){
        if(m>>i&1){
            int t=1LL<<i;
            int l=(n/t/2)*t,r=((n>>i&1)*(n&(t-1)));
            (ans+=l+r)%=mod;
        }
    }
    cout<<ans;
}