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
    int ans = n, t1 = 0, t2 = 0;
    int c = 1;

    V<int> a, b;
    FOR(i, 1, n) {
        if (s[i] == 'a') {
            a.eb(i);
        } else {
            b.eb(i);
        }
    }

    auto calc = [&](V<int> w) {
        if (!sz(w)) return int(0);
        int t = sz(w);
        c = 1;
        int tot = 0, mid = w[t / 2];
        FORD(i, 0, t / 2 - 1) {
            tot += (mid - w[i] - c);
            c++;
        }
        c = 1;
        FOR(i, t / 2 + 1, t - 1) {
            tot += (w[i] - mid - c);
            c++;
        }
        return tot;
    };

    ans = min({calc(a), calc(b)});

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
