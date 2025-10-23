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
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;

    V<int> suf(n + 1, 0);
    int mod = 2019;
    int t = 1;
    FORD(i, 1, n) {
        suf[i] = (s[i] - '0') * t + suf[i + 1];
        suf[i] %= mod;
        if (suf[i] < 0) suf[i] += mod;
        t *= 10;
        t %= mod;
    }

    map<int, int> mp;
    mp[0] = 1;
    int ans = 0;
    FOR(i, 1, n) {
        ans += mp[suf[i]];
        mp[suf[i]]++;
    }
    cout << ans;
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