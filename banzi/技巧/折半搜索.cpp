
int n,x;
int w[N];

VI calc(int l,int r){
    int len=r-l+1;

    VI ans;
    
    FOR(i,0,(1<<len)-1){
        int s=0;
        FOR(j,0,len-1){
            if(i>>j&1){
                s+=w[l+j];
            }
        }
        ans.pb(s);
    }
    return ans;
}

void solve() {
    cin>>n>>x;
    
    FOR(i,0,n-1)cin>>w[i];

    VI a=calc(0,n/2-1);
    VI b=calc(n/2,n-1);

    sort(ALL(a));
    sort(ALL(b));

    int ans=0;

    for(auto p:a){
        auto l=lower_bound(ALL(b),x-p);
        auto r=upper_bound(ALL(b),x-p);
        ans+=r-l;
    }
    cout<<ans;

}