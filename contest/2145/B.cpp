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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    string ans(n + 1, '+');

    if (n == 1) {
        cout << "-" << endl;
        RE;
    }

    if (n == k) {
        FOR(i, 1, n) cout << "-";
        cout << endl;
        RE;
    }

    V<int> a(k + 1, 0), b(k + 1, 0);

    int l = 1, r = n;
    int cnt = 0;

    FOR(i, 1, k) {
        if (s[i] == '0') {
            ans[l++] = '-';
        } else if (s[i] == '1') {
            ans[r--] = '-';
        } else {
            cnt++;
        }
    }

    while (cnt--) {
        if (l <= r) {
            ans[l++] = '?';
        }
        if (l <= r) {
            ans[r--] = '?';
        }
    }

    FOR(i, 1, n) cout << ans[i];
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
