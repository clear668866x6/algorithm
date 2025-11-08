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
    string s;
    cin >> s;
    s = ' ' + s;

    V<int> len;
    len.eb(n);

    FOR(i, 1, 70) {
        int t = len[i - 1];
        if (t > 1e18) break;
        len.eb(t * 2 + 1);
    }

    auto left = prev(lower_bound(ALL(len), k));
    auto right = upper_bound(ALL(len), k);

    int l = *left, r = *right;

    if (k == l + 1) {
        cout << 'a' << endl;
        RE;
    }

    int t = 0, cur = r;
    while (k > n) {
        int mid = (cur - 1) / 2;
        if (k == mid + 1) {
            t %= 26;
            cout << char(t + 'a') << endl;
            RE;
        }

        if (k > mid + 1) {
            k -= (mid + 1);
            t++;
        }
        cur = (cur - 1) / 2;
    }

    t %= 26;

    cout << char((s[k] - 'a' + t) % 26 + 'a') << endl;
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
