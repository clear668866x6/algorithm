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
    int n;
    string s;
    cin >> n >> s;

    s = ' ' + s;

    int ans = n;

    string sa = " ", sb = " ";

    FOR(i, 1, n) {
        if (i & 1) {
            sa += '0';
            sb += '1';
        } else {
            sa += '1';
            sb += '0';
        }
    }

    auto calc = [&](string st) {
        V<int> c(1, 0);
        FOR(i, 1, n) {
            if (st[i] != s[i]) {
                c.eb(s[i] - '0');
            }
        }

        int m = sz(c) - 1;

        int cnt0 = 0, cnt1 = 0, ans = 0;

        FOR(i, 1, m) {
            if (c[i] == 1) {
                if (cnt0 > 0) {
                    cnt0--;
                    cnt1++;
                } else {
                    ans++;
                    cnt1++;
                }
            } else {
                if (cnt1 > 0) {
                    cnt1--;
                    cnt0++;
                } else {
                    ans++;
                    cnt0++;
                }
            }
        }

        return ans;
    };

    ans = min(calc(sa), calc(sb));

    cout << ans << endl;
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
