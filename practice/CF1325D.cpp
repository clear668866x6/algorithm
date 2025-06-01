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
    int a,b;
    cin>>a>>b;
    if(a>b||(b-a)&1){
        cout<<-1<<endl;
        RE;
    }

    if(a==b){
        if(!a){
            cout<<0<<endl;
        }else{
            cout<<1<<endl<<a<<endl;
        }
        RE;
    }

    V<int> ans;
    int res=0,t=(b-a)/2;
    bool f=false;

    FORD(k,0,62){
        if(a>>k&1){
            res|=(1LL<<k);
            if(t>>k&1){
                f=1;
            }        
        }
    }
    if(f){
        ans.pb(res);
        ans.pb(t);
    }else{
        ans.pb(res|t);
    }
    ans.pb(t);

    cout<<ans.sz<<endl;
    for(auto x:ans)cout<<x<<' ';

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