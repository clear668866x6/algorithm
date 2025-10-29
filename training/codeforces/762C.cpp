#include <algorithm>
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
    string s, t;
    cin >> s >> t;
    int len1 = sz(s), len2 = sz(t);
    s = ' ' + s, t = ' ' + t;

    int now = 1;
    V<int> s1(len1 + 1, 0), s2(len1 + 2, 0);

    FOR(i, 1, len1) {
        if (t[now] == s[i]) {
            now++;
        }
        s1[i] = now - 1;
    }

    now = len2;

    FORD(i, 1, len1) {
        if (t[now] == s[i]) {
            now--;
        }
        s2[i] = now + 1;
    }

    s2[len1 + 1] = 1e18;

    int mn = 1e18;
    int ansl = 0, ansr = 0;

    FOR(i, 0, len1 - 1) {
        int r = *upper_bound(s2.begin() + i + 1, s2.end(), s1[i]);
        int l = s1[i];
        if (r - l - 1 < mn) {
            mn = r - l - 1;
            ansl = l, ansr = r;
        }
    }

    int r = len2 + 1;
    int l = s1[len1];
    if (r - l - 1 < mn) {
        mn = r - l - 1;
        ansl = l, ansr = r;
    }

    string mx;

    FOR(i, 1, ansl) mx += t[i];
    FOR(i, ansr, len2) mx += t[i];

    if (!sz(mx)) mx = '-';
    cout << mx;
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