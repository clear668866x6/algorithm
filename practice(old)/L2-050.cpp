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

string s[N];
int n,q;

void solve() {
    cin>>n;

    map<string,VI>v;

    cin.ignore();
    FOR(i,1,n){
        getline(cin,s[i]);
        string t,p;
        p=' '+s[i];

        FOR(j,0,p.sz-2){
            if(p[j]==' '&&p[j+1]!=' '){
                t+=p[j+1];
            }
        }
        v[t].pb(i);
    }

    cin>>q;
    cin.ignore();
    while(q--){
        string t;
        getline(cin,t);
        string a,p;
        p=' '+t;
        FOR(j,0,p.sz-2){
            if(p[j]==' '&&p[j+1]!=' '){
                a+=p[j+1];
            }
        }
        vector<string>ans;

        FOR(i,0,v[a].sz-1){
            ans.pb(s[v[a][i]]);
        }
        if(!ans.sz){
            cout<<t<<endl;
            continue;
        }

        sort(ALL(ans));

        FOR(i,0,ans.sz-1){
            if(i==ans.sz-1){
                cout<<ans[i]<<endl;
            }else{
                cout<<ans[i]<<"|";
            }
        }

    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}