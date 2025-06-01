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
//很好的技巧：偶数变成奇数如果不影响整体的话，我们可以尝试同时除以2

void solve() {
    int n;
    cin>>n;

    V<int> w(n+1,0);
    int sum=0;
    FOR(i,1,n)cin>>w[i],sum+=w[i];

    if(sum&1){
        cout<<0<<endl;
        RE;
    }

    V<int>f(sum/2+1,0);
    f[0]=1;

    FOR(i,1,n){
        FORD(j,w[i],sum/2){
            f[j]|=f[j-w[i]];
        }
    }

    if(!f[sum/2]){
        cout<<0<<endl;
        RE;
    }

    cout<<1<<endl;
    FOR(i,1,n){
        if(w[i]&1){
            cout<<i<<endl;
            RE;
        }
    }

    FOR(k,0,32){
        FOR(i,1,n){
            if(w[i]>>k&1){
                cout<<i<<endl;
                RE;
            }
        }
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