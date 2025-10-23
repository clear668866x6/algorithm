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
    V<int> w(n + 1, 0), c;
    map<int, int> mp;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;
    c = w;
    V<int> pre(n + 1, 0), suf(n + 2, 0);

    sort(ALL(w));
    w.erase(unique(ALL(w)), w.end());
    n = sz(w) - 1;

    int tot = mp[w[1]];

    FOR(i, 2, n) {
        int del = w[i] - w[i - 1];
        pre[i] = pre[i - 1] + del * tot;
        tot += mp[w[i]];
    }

    tot = mp[w[n]];

    FORD(i, 1, n - 1) {
        int del = w[i + 1] - w[i];
        suf[i] = suf[i + 1] + del * tot;
        tot += mp[w[i]];
    }

    map<int, int> mp2;

    FOR(i, 1, n) {
        mp2[w[i]] = (pre[i] + suf[i] + (sz(c) - 1));
    }

    FOR(i, 1, sz(c) - 1) {
        cout << mp2[c[i]] << ' ';
    }
    cout << endl;
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
