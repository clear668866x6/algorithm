
void solve() {
    cin>>s>>x;
    n=s.sz;

    while(x--){
        string ans=s;
        FOR(i,0,s.sz-1){
            string t=s;
            t.erase(i,1);
            ans=min<string>(ans,t);
        }
        s=ans;
    }
    reverse(ALL(s));
    while(s.back()=='0'&&s.sz>1)s.pop_back();
    reverse(ALL(s));
    cout<<s;
}