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
//错误点：错在没有考虑跨越区间的情况
/*
也就是：
2 3 4 
6 8
Yes

*/

void solve() {
    int n,a,b;
    cin>>n>>a>>b;

    V<int>w(n);
    FOR(i,0,n-1)cin>>w[i],w[i]%=(a+b);
    
    sort(ALL(w));
    int mn=*min_element(ALL(w)),mx=*max_element(ALL(w));

    if(mx-mn+1>a){
        FOR(i,0,n-1){
            if(w[i]>a-1){
                mx=w[i];
                break;
            }
        }
        FORD(i,0,n-1){
            if(w[i]<=a-1){
                mn=w[i];
                break;
            }
        }
        mn+=(a+b);

        // cout<<mn<<' '<<mx<<endl;

        if(abs(mx-mn)+1>a){
            No;
        }else{
            Yes;
        }

    }else{
        Yes;
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