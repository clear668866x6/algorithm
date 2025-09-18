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

    V<int> ans(n + 1, 0);
    int num = 1;

    struct E {
        int len, l, r;
        bool operator<(const E &t) const {
            if (len == t.len) return l > t.l;
            return len < t.len;
        }
    };

    priority_queue<E> q;
    q.push({n, 1, n});

    while (num <= n) {
        auto [len, l, r] = q.top();
        q.pop();
        int mid = (l + r) >> 1;
        ans[mid] = num++;
        if (mid - l >= 0) {
            q.push({mid - 1 - l, l, mid - 1});
        }
        if (r - mid - 1 >= 0) {
            q.push({r - mid - 1, mid + 1, r});
        }
    }

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
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
