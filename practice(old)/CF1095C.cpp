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
//从小出发，从小到大：从最小的个数开始左，然后通过运算让值越来越大
void solve () {
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    if (k <= n && k >= __builtin_popcount (n)){
        YES;
        V<int>num;
        k -= __builtin_popcount (n);
        while (n){
            num.eb (n & 1);
            n /= 2;
        }

        while (k--){
            while (num.back () == 0)num.pop_back ();
            num[num.sz - 1]--;
            num[num.sz - 2] += 2;
        }

        FOR (i, 0, num.sz - 1){
            FOR (j, 1, num[i]){
                cout << (1 << i) << ' ';
            }
        }

        cout << endl;
    } else{
        NO;
    }
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}