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
//遇到判断YES和NO的题目时，不要怕用dp导致范围问题，有的时候有的题目就是判断范围是否在一定区域内来判断是否是YES和NO

void solve() {
    int n,m;
    cin>>n>>m;

    V<V<int>>w(n+2,V<int>(m+2,0)),f1(n+2,V<int>(m+2,0)),f2(n+2,V<int>(m+2,0));

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>w[i][j];
        }
    }

    if((n+m-1)&1){
        NO;
        RE;
    }
    
    FOR(i,1,m){
        f1[1][i]=f2[1][i]=f1[1][i-1]+w[1][i];
    }
    FOR(i,1,n){
        f1[i][1]=f2[i][1]=f1[i-1][1]+w[i][1];
    }

    FOR(i,2,n){
        FOR(j,2,m){
            f1[i][j]=max(f1[i][j-1],f1[i-1][j])+w[i][j];
            f2[i][j]=min(f2[i][j-1],f2[i-1][j])+w[i][j];
        }
    }

    if(f1[n][m]>=0&&f2[n][m]<=0){
        YES;
    }else{
        NO;
    }

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