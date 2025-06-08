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
    int n;
    cin >> n;
    V<int>w(n);
    for (auto& x : w)cin >> x;

    V<array<int, 3>>ans;

    int t = w[n - 2] - w[n - 1];

    bool f = false;

    FOR(i, 1, n - 1){
        if (w[i] < w[i - 1]){
            f = 1;
            break;
        }
    }

    if (!f){
        cout << 0 << endl;
        RE;
    }

    FOR(i, 0, n - 3)w[i] = t, ans.pb({ i + 1,n - 1,n });

    FOR(i, n - 2, n - 1){
        if (w[i] < w[i - 1]){
            cout << -1 << endl;
            RE;
        }
    }
    cout << ans.sz << endl;
    for (auto [x, y, z] : ans){
        cout << x << ' ' << y << ' ' << z << endl;
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