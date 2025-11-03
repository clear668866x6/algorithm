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
    int n, m;
    cin >> n >> m;

    V<int> d(2e4 + 10, 1e18);

    d[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        int t1 = t * 2;
        if (t1 <= 2e4) {
            if (d[t1] > d[t] + 1) {
                d[t1] = d[t] + 1;
                q.push(t1);
            }
        }
        int t2 = t - 1;
        if (t2 >= 1) {
            if (d[t2] > d[t] + 1) {
                d[t2] = d[t] + 1;
                q.push(t2);
            }
        }
    }

    cout << d[m];
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