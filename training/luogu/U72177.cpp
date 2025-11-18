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

struct BiTTree {
    static constexpr int N = 2e5 + 10;

    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += tr[i];
        return ans;
    }

    int kth(int k, int n) {
        int pos = 0, cnt = 0;
        FORD(i, 0, 20) {
            int ne = pos + (1 << i);
            if (ne <= n && ne - cnt - tr[ne] < k) {
                pos = ne;
                cnt += tr[ne];
            }
        }
        return pos + 1;
    }
} A;
// https://www.luogu.com.cn/article/vb1m6qp0
void solve() {
    int n, m;
    cin >> n >> m;

    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) {
        int t = a[i] - A.query(a[i]);
        A.add(a[i], 1);
        a[i] = t - 1;
    }

    a[n] += m;

    // unkown进制变换。
    FORD(i, 1, n) {
        a[i - 1] += a[i] / (n - i + 1);
        a[i] %= (n - i + 1);
    }

    memset(A.tr, 0, sizeof A.tr);

    FOR(i, 1, n) {
        a[i]++;
        int t = A.kth(a[i], n);
        cout << t << ' ';
        A.add(t, 1);
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