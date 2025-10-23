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
    int n;
    string s;
    cin >> n >> s;

    s = ' ' + s;

    int c = 0;

    V<int> w(1, 1);

    FOR(i, 1, n * 2) {
        if (s[i] == '(')
            c++;
        else
            c--;
        if (!c) {
            w.eb(i);
        }
    }
    int t = w.sz;
    int ans = (w[1] - w[0] + 1) / 2 - (t - 2);

    int cnt = 0;

    FOR(i, 2, n * 2) {
        if (s[i - 1] == '(' && s[i] == ')')
            cnt++;
    }

    ans -= (cnt - (t - 1));

    FOR(i, 2, w.sz - 1) { ans += (w[i] - w[i - 1]) / 2; }

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
