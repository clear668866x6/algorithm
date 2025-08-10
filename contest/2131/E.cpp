#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;

    V<int> a(n + 1), b(n + 1);

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    V<int> pre(n + 1, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] ^ a[i];

    map<int, V<int>> pos;
    FOR(i, 1, n) { pos[pre[i]].eb(i); }

    int R = n;

    FORD(i, 1, n) {
        int t = pre[i - 1] ^ b[i];
        auto it = pos.find(t);
        if (it == pos.end()) {
            NO;
            RE;
        }
        auto& vec = it->second;
        auto up = upper_bound(vec.begin(), vec.end(), R);
        if (up == vec.begin()) {
            NO;
            RE;
        }
        --up;
        int k = *up;
        if (k < i) {
            NO;
            RE;
        }
        R = k;
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
