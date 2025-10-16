#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
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
    string s;
    cin >> n >> s;
    s = ' ' + s;

    if (n & 1) {
        cout << -1 << endl;
        RE;
    }

    map<char, int> mp, mp2;
    int mx = 0;
    FOR(i, 1, n) mp[s[i]]++;

    for (auto [x, y] : mp) {
        mx = max(mx, y);
    }

    if (mx > n / 2) {
        cout << -1 << endl;
        RE;
    }

    if (mp[s[1]] == n) {
        cout << -1 << endl;
        RE;
    }

    int ans = 0;

    FOR(i, 1, n / 2) {
        if (s[i] == s[n - i + 1]) {
            ans++;
            mp2[s[i]]++;
        }
    }
    mx = 0;
    for (auto [x, y] : mp2) {
        mx = max(mx, y);
    }

    cout << max((ans + 1) / 2, mx) << endl;
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
