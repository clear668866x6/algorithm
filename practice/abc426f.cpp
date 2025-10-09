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

struct SegmentTree {
    static constexpr int N = 3e5 + 10;
    struct E {
        int l, r, tag, mn, cnt;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
        tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
    }

    void evel(int u, int tag) {
        tr[u].mn += tag;
        tr[u].tag += tag;
    }

    void pushdown(int u) {
        if (tr[u].tag) {
            evel(u << 1, tr[u].tag);
            evel(u << 1 | 1, tr[u].tag);
            tr[u].tag = 0;
        }
    }

    void build(int u, int l, int r, V<int> &w) {
        tr[u] = {l, r};
        if (l == r) {
            tr[u] = {l, r, 0, w[l], 1};
            RE;
        }

        int mid = (l + r) >> 1;
        build(u << 1, l, mid, w), build(u << 1 | 1, mid + 1, r, w);
        pushup(u);
    }

    int modify(int u, int l, int r, int k) {
        if (!tr[u].cnt) return 0;
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) {
            if (tr[u].mn > k) {
                evel(u, -k);
                return tr[u].cnt * k;
            }
        }
        if (tr[u].l == tr[u].r) {
            int ans = tr[u].cnt * tr[u].mn;
            tr[u].cnt = 0;
            tr[u].mn = 1e18;
            tr[u].tag = 0;
            return ans;
        }

        int ans = 0;
        pushdown(u);
        ans += modify(u << 1, l, r, k);
        ans += modify(u << 1 | 1, l, r, k);
        pushup(u);
        return ans;
    }

} A;

void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1);
    FOR(i, 1, n) cin >> w[i];

    A.build(1, 1, n, w);

    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << A.modify(1, l, r, k) << endl;
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