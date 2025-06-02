#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve() {
    int n,q;
    cin>>n>>q;
    set<int>s;
    V<int> w(n+1,0),pre(q+1,0);
    map<int,V<int>>mp;

    FOR(i,1,q){
        int x;
        cin>>x;
        if(s.count(x))s.erase(x),mp[x].pb(i-1);
        else{
            s.insert(x);
            mp[x].pb(i);
        }
        int t=s.sz;
        pre[i]=pre[i-1]+t;
    }

    for(auto x:s){
        mp[x].pb(q);
    }

    FOR(i,1,n){
        FOR2(j,1,mp[i].sz-1,2){
            w[i]+=(pre[mp[i][j]]-pre[mp[i][j-1]-1]);
        }
        cout<<w[i]<<" \n"[i==n];
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}