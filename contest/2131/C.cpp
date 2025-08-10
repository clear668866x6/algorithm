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
    int n, k;
    cin >> n >> k;

    V<int> a(n), b(n);

    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;

    if (k == 1) {
        YES;
        RE;
    }

    FOR(i, 0, n - 1) { a[i] %= k, b[i] %= k; }

    map<int, int> mp2;

    FOR(i, 0, n - 1) mp2[b[i]]++;

    FOR(i, 0, n - 1) {
        if (mp2[a[i]]) {
            mp2[a[i]]--;
        } else if (mp2[k - a[i]]) {
            mp2[k - a[i]]--;
        }
    }

    FOR(i, 0, n - 1) {
        if (mp2[b[i]]) {
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
