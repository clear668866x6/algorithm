
void solve() {
    cin>>s>>x;
    n=s.sz;
    int l=0,r=x;
    x=n-x;
    string ans;
    char mn=*min_element(ALL(s));

    while(x--){
        char m='9';
        for(int i=l;i<=r&&m!=mn;i++){
            if(m>s[i]&&(ans.sz||s[i]!='0')){
                m=s[i];
                l=i+1;
            }
        }
        ans+=m,r++;
    }
    cout<<ans<<endl;
}
