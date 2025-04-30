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

string t;
int f[N];

namespace ACauto{
    string s;
    int n;
    int id[N];
    int tr[N][30],ne[N];
    int cnt[N],idx;
    bool vis[N];
    int q[N];
    
    int insert(string t){
        int p=0;
        FOR(i,0,t.sz-1){
            int u=t[i]-'a';
            if(!tr[p][u])tr[p][u]=++idx;
            p=tr[p][u];
            f[p]++;
        }
        return p;
    }
    
    void build(){
        int hh=0,tt=-1;
        FOR(i,0,25){
            if(tr[0][i])q[++tt]=tr[0][i];
        }
    
        while(hh<=tt){
            int t=q[hh++];
    
            FOR(i,0,25){
                int j=tr[t][i];
                if(j)ne[j]=tr[ne[t]][i],q[++tt]=j;
                else tr[t][i]=tr[ne[t]][i];
            }
        }

        FORD(i,0,idx-1){
            f[ne[q[i]]]+=f[q[i]];
        }
    }
}

using namespace ACauto;

void solve() {
    cin>>t>>n;

    FOR(i,1,n){
        string s;
        cin>>s;
        id[i]=insert(s);
    }
    build();

    FOR(i,1,n)cout<<f[id[i]]<<endl;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}