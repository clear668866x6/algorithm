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
    int n,m;
    cin>>n>>m;
    V<V<int>>g(n+1);
    V<int>p(n+1,0);

    FOR(i,1,n)p[i]=i;

    function<int(int)> find=[&](int x){
        if(x!=p[x])p[x]=find(p[x]);
        return p[x];
    };

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b)){
            p[find(a)]=find(b);
            g[a].eb(b);
            g[b].eb(a);
        }
    }

    V<int>dep(n+2,0);
    int c1=0,c2=0;
    dep[1]=1;

    function<void(int,int)> dfs=[&](int u,int fa){
        if(dep[u]%2==0)c1++;
        else c2++;

        for(auto& j:g[u]){
            if(j==fa)continue;
            dep[j]=dep[u]+1;
            dfs(j,u);
        }
    };

    dfs(1,0);

    if(c2>c1){
        cout<<c1<<endl;
        FOR(i,1,n){
            if(dep[i]%2==0)cout<<i<<' ';
        }
    }else{
        cout<<c2<<endl;
        FOR(i,1,n){
            if(dep[i]%2==1)cout<<i<<' ';
        }
    }
    cout<<endl;

}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    while (Task--) {
        solve();
    }

    return 0;
}