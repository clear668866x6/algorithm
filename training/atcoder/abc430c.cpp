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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s = ' ' + s;
    V<int> prea(n + 1, 0), preb(n + 1, 0);
    FOR(i, 1, n) {
        prea[i] = prea[i - 1] + (s[i] == 'a');
        preb[i] = preb[i - 1] + (s[i] == 'b');
    }

    int r = 1;
    int cnt = 0;
    FOR(l, 1, n) {
        while (r <= n && prea[r] - prea[l - 1] < a) {
            r++;
        }
        auto it = lower_bound(preb.begin() + r, preb.end(), preb[l - 1] + b);
        if (it != preb.begin() + r) {
            it--;
            int rr = it - preb.begin();
            cnt += rr - r + 1;
        }
    }

    cout << cnt << endl;
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