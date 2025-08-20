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

    FOR(i, 1, n) {
        if (!w[i]) {
            w[i] = 1e18;
        }
    }

    map<int, V<int>> mp;

    FOR(i, 1, n) mp[w[i]].eb(i);

    int m;
    cin >> m;

    while (m--) {
        string s;
        cin >> s;

        if (sz(s) != n) {
            NO;
            continue;
        }

        s = ' ' + s;

        map<char, V<int>> mp2;

        FOR(i, 1, n) mp2[s[i]].eb(i);

        if (sz(mp) != sz(mp2)) {
            NO;
        } else {
            map<char, int> mp3;

            bool f = false;
            FOR(i, 1, n) {
                if (!mp3[s[i]]) {
                    mp3[s[i]] = w[i];
                } else {
                    if (mp3[s[i]] != w[i]) {
                        NO;
                        f = 1;
                        break;
                    }
                }
            }
            if (!f) YES;
        }
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
