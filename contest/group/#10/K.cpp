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
    int n, k;
    cin >> n >> k;

    V<int> w(n + 1);

    FOR(i, 1, n) cin >> w[i];

    FOR(i, 1, n) {
        if (!w[i]) w[i] = -1e18;
    }

    V<int> pre(n + 1, 0), suf(n + 2, 0);

    FOR(i, 1, n) {
        pre[i] = max(pre[i - 1] + w[i], w[i]);
    }

    FORD(i, 1, n) {
        suf[i] = max(suf[i + 1] + w[i], w[i]);
    }

    int j = 1, id = 0, c = 0, ans = max(*max_element(ALL(pre)), *max_element(ALL(suf)));

    FOR(i, 1, n) {
        if (w[i] == -1e18) c++;
        if (c == k) {
            id = i;
            break;
        }
    }

    if (c < k) {
        cout << n << endl;

        FOR(i, 1, n) cout << "1 ";
        RE;
    }

    int l = 0, r = 0;

    if (max<int>(0, suf[id + 1]) + id > ans) {
        ans = max<int>(0, suf[id + 1]) + id;
        l = 1, r = id;
    }

    FOR(i, id + 1, n) {
        c += (w[i] == -1e18);
        while (j <= i && c >= k) {
            c -= (w[j] == -1e18);
            j++;
        }
        if (c < k) j--, c++;
        if (max<int>(0, suf[i + 1]) + max<int>(0, pre[j - 1]) + (i - j + 1) > ans) {
            ans = max<int>(0, suf[i + 1]) + max<int>(0, pre[j - 1]) + (i - j + 1);
            l = j, r = i;
        }
    }

    cout << ans << endl;

    FOR(i, 1, n) {
        if (w[i] == -1e18) w[i] = 0;
    }

    FOR(i, 1, n) {
        if (i < l || i > r) {
            cout << w[i] << ' ';
        } else {
            cout << "1 ";
        }
    }
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