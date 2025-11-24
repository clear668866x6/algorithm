#include <bits/stdc++.h>
#include <queue>
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
    struct E {
        int a, b;
        bool operator<(const E &t) const {
            if (b == t.b) return a > t.a;
            return b < t.b;
        }
    };
    V<E> w(n + 1);
    FOR(i, 1, n) cin >> w[i].a >> w[i].b;

    sort(w.begin() + 1, w.end());

    int ans = 0;

    FOR(l, 1, n) {
        priority_queue<int> q;
        int s = 0;
        FOR(r, l, n) {
            s += w[r].a;
            q.push(w[r].a);
            int p = s + w[r].b - w[l].b;
            while (!q.empty() && p > k) {
                s -= q.top();
                p -= q.top();
                q.pop();
            }
            ans = max(ans, sz(q));
        }
    }

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
