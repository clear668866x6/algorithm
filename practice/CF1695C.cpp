#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
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
//memory-exceed 

void solve() {
    int n,m;
    cin>>n>>m;

    V<V<int>>w(n+2,V<int>(m+2,0)),vis(n+2,V<int>(m+2,0));

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>w[i][j];
        }
    }

    if((n+m-1)&1){
        NO;
        RE;
    }
    
    array<int,2>dx={0,1},dy={1,0};
    struct E{
        int x,y,c1,c2;
    };
    queue<E>q;
    q.push({1,1,w[1][1]==1,w[1][1]==-1});
    int t=(n+m-1)/2;

    while(q.sz){
        auto [x,y,c1,c2]=q.front();
        q.pop();
        // cout<<x<<' '<<y<<' '<<c1<<' '<<c2<<endl;
        if(c1>t||c2>t)continue;
        vis[x][y]=1;
        if(c1==c2&&x==n&&y==m){
            YES;
            RE;
        }

        FOR(i,0,1){
            int a=dx[i]+x,b=dy[i]+y;
            if(a<1||b<1||a>n||b>m||vis[a][b])continue;
            q.push({a,b,c1+(w[a][b]==1),c2+(w[a][b]==-1)});
        }
    }
    NO;
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