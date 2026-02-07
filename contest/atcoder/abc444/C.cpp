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
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];
    sort(ALL(w));

    if (n == 1) {
        cout << w[1] << endl;
        RE;
    }

    int t = w[n];

    set<int> ans;

    if (w[1] == w[n]) ans.insert(w[1]);

    map<int, int> mp, mp2;

    FOR(i, 1, n) mp[w[i]]++, mp2[w[i]]++;

    int tot = accumulate(ALL(w), 0ll) / (n / 2);

    FOR(i, 1, n) {
        if (tot == w[i]) {
            mp[tot]--;
        } else if (tot - w[i] != w[i] && mp[tot - w[i]]) {
            mp[w[i]]--;
            mp[tot - w[i]]--;
        } else if (mp[tot - w[i]] > 1) {
            mp[tot - w[i]] -= 2;
        }
    }

    bool f = false;

    for (auto [x, y] : mp) {
        if (y > 0) {
            f = 1;
            break;
        }
    }

    if (!f) {
        ans.insert(tot);
    }

    FOR(i, 1, n) {
        if (t == w[i]) {
            mp2[t]--;
        } else if (t - w[i] != w[i] && mp2[t - w[i]]) {
            mp2[w[i]]--;
            mp2[t - w[i]]--;
        } else if (mp2[t - w[i]] > 1) {
            mp2[t - w[i]] -= 2;
        }
    }

    f = 0;
    for (auto [x, y] : mp2) {
        if (y > 0) {
            f = 1;
            break;
        }
    }

    if (!f) {
        ans.insert(t);
    }

    for (auto x : ans) cout << x << ' ';
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