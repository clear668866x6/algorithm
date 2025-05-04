#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
using PII = pair<int, int>;
using TII = tuple<int, int, int>;
#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define BSI basic_string<int>
#define BSPI basic_string<PII>
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define VI vector<int>
#define VII vector<vector<int>>
#define VPII vector<PII>
#define lowbit(x) ((x)&(-x))
#define RE return;
#define RET return true;
#define REF return false;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define fi first
#define se second
#define sz size()
constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
string s;

string min(string a,string b){
    if(a.sz>b.sz){
        return b;
    }
    if(a.sz<b.sz){
        return a;
    }
    if(a>b)return b;
    return a;
}

void solve() {
    cin>>n>>s;

    VI w(n+1,0);

    FOR(i,1,n){
        w[i]=s[i-1]-'0';
    }

    if(w[1]^w[n]){
        cout<<"empty"<<endl;
    }else{

        FOR(i,2,n-1){
            if(w[i]==w[i+1]&&(w[i]^w[1])){
                cout<<"empty"<<endl;
                RE;
            }
        }

        string ans;

        VI v0,v1;

        FOR(i,1,n){
            if(w[i])v1.pb(i);
            else v0.pb(i);
        }

        if(w[1]){
            if(v0.sz==0){
                cout<<s<<endl;
                RE;
            }
            // cout<<s.substr(v0[v0.sz-1],n-v0[v0.sz-1])<<endl;
            // if(v0.sz==1){
                ans=min(s.substr(0,v0[v0.sz-1]-1),s.substr(v0[v0.sz-1],n-v0[v0.sz-1]));
                ans=min(ans,s.substr(0,v0[0]-1));
                ans=min(ans,s.substr(v0[0],n-v0[0]));
                // }else{
            // cout<<s.substr(0,v0[v0.sz-1])<<endl;
                // cout<<v0[0]<<endl;8
                FOR(i,0,v0.sz-2){
                    ans=min(ans,s.substr(v0[i],v0[i+1]-v0[i]-1));
                }
            // }
        }else{
            if(v1.sz==0){
                cout<<s<<endl;
                RE;
            }
            // if(v1.sz==1){
                ans=s.substr(0,v1[v1.sz-1]-1);
                ans=min(ans,s.substr(v1[v1.sz-1],n-v1[v1.sz-1]));
                ans=min(s.substr(0,v1[0]-1),ans);
                ans=min(ans,s.substr(v1[0],n-v1[0]));
            // }else{
                // cout<<v0[0]<<endl;
                FOR(i,0,v1.sz-2){
                    ans=min(ans,s.substr(v1[i],v1[i+1]-v1[i]-1));
                }
            // }
        }

        cout<<ans<<endl;
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}