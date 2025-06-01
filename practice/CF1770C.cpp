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
//对于这种要求找一个数使得满足xx性质的题目，数又比较大的时候，我们可以考虑对这个数模一下看看。

void solve() {
    int n;
    cin>>n;
    V<int>w(n+1,0);

    map<int,int>mp;
    FOR(i,1,n)cin>>w[i],mp[w[i]]++;

    for(auto [x,y]:mp){
        if(y>1){
            NO;
            RE;
        }
    }

    FOR(k,2,n/2){
        map<int,int>mp2;
        FOR(i,1,n){
            mp2[w[i]%k]++;
        }
        int mn=1e18;

        FOR(i,0,k-1)mn=min(mn,mp2[i]);

        if(mn>1){
            NO;
            RE;
        }
    }
    YES;
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