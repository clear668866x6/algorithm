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

    V<int> len(40, 0), sum(40, 0), len2(40, 0), len3(40, 0);
    len[1] = 4;
    len2[1] = 2;
    int tot = 4;
    sum[1] = 4;
    FOR(i, 2, 32) {
        len[i] = 2 * tot + 1;
        len2[i] = tot + sum[i - 1];
        sum[i] = sum[i - 1] + len[i];
        tot += len[i];
    }

    len3[1] = 3;
    FOR(i, 2, 32) {
        len3[i] = sum[i] - 1;
    }

    int ans = 0;

    FOR(i, 1, n) {
        if (s[i] == '1') {
            ans += sum[n - i];
        } else if (s[i] == '2') {
            ans += len2[n - i + 1];
        } else if (s[i] == '3') {
            ans += len3[n - i + 1];
        }
    }

    if (s.back() == '1') ans++;

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