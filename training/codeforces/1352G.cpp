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
    cin >> n;

    if (n < 4) {
        cout << -1 << endl;
        RE;
    }

    deque<int> q;

    V<int> vis(n + 1, 0);
    q.push_back(n);
    vis[n] = 1;
    FORD2(i, 1, n - 2, 2) {
        q.push_front(i);
        vis[i] = 1;
    }

    int cnt = 0;

    FORD2(i, 1, n - 3, 2) {
        cnt++;
        if (cnt == 2) {
            q.push_back(n - 1);
            vis[n - 1] = 1;
        }
        vis[i] = 1;
        q.push_back(i);
    }

    FOR(i, 1, n) {
        if (!vis[i]) {
            q.push_back(i);
        }
    }

    for (auto x : q) {
        cout << x << ' ';
    }
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
