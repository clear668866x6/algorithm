
void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    int ans=0,a=0,b=0;
    w[0]=1e18;
    //b 记录了当前上升段的长度
    //a 记录了上一个波峰前上升段的长度

    FOR(i,1,n){
        if(w[i]>w[i-1]){
            ans+=a;
            b++;
        }else if(b>0){
            a=b;
            b=0;
        }
    }

    cout<<ans;
}