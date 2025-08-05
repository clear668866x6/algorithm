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
#define sz size()

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    FOR(i, 0, n - 1) {
        if (s[i] == 'o') {
            if (i + 1 < n && s[i + 1] == '?')
                s[i + 1] = '.';
            if (i - 1 >= 0 && s[i - 1] == '?')
                s[i - 1] = '.';
            k--;
        }
    }

    if (!k) {
        FOR(i, 0, n - 1) {
            if (s[i] == '?')
                s[i] = '.';
        }
        cout << s << endl;
        RE;
    }

    V<int> pre(n + 2, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] + (s[i - 1] == '?');

    V<int> d;

    FOR(i, 0, n - 1) {
        if (s[i] == '?') {
            int j = i;
            while (j < n && s[j] == '?')
                j++;
            d.eb(i + 1);
            d.eb(j);
            i = j - 1;
        }
    }

    int cnt = 0;

    FOR2(i, 1, d.sz - 1, 2) { cnt += (pre[d[i]] - pre[d[i - 1] - 1] + 1) / 2; }

    if (cnt == k) {

        FOR2(i, 1, d.sz - 1, 2) {
            int del = pre[d[i]] - pre[d[i - 1] - 1];
            if ((del & 1) && (del + 1) / 2 <= k) {
                bool f = false;

                FOR(j, d[i - 1] - 1, d[i] - 1) {
                    if (!f) {
                        s[j] = 'o', k--;
                        f = 1;
                    } else if (f) {
                        s[j] = '.';
                        f = 0;
                    }
                }
            }
        }
    }

    cout << s << endl;
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