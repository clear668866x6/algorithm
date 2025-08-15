#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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
    int n, m;
    cin >> n >> m;

    V<array<int, 2>> w(m + 1);
    V<int> d(n + 1, 0);

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        w[i] = {a, b};
        d[a]++, d[b]++;
    }

    V<int> ans(m + 1, 0);

    if (*min_element(d.begin() + 1, d.end()) < n - 1) {
        cout << 2 << endl;
        int t = *min_element(d.begin() + 1, d.end());

        int id = 0;

        FOR(i, 1, n) {
            if (d[i] == t) {
                id = i;
                break;
            }
        }
        FOR(i, 1, m) {
            if (w[i][0] == id || w[i][1] == id)
                cout << "2 ";
            else
                cout << "1 ";
        }
        cout << endl;
    } else {
        cout << 3 << endl;
        int cnt = 1;
        FOR(i, 1, m) {
            if (w[i][0] == 1 && cnt < n - 1) {
                cnt++;
                cout << "2 ";
            } else if (w[i][0] == 1 && cnt == n - 1) {
                cout << "3 ";
            } else {
                cout << "1 ";
            }
        }
        cout << endl;
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
