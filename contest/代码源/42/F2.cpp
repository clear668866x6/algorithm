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
    static constexpr int N = 1e5 + 10;

    struct E {
        int l, r, cnt[22], tag[22]; // 这边注意的是这种拥有多个tag的时候，对tag赋值i是最好的。因为这道题跟交换有关
    } tr[N << 2];

    void pushup(int u) {
        FOR(i, 1, 20) tr[u].cnt[i] = (tr[u << 1].cnt[i] + tr[u << 1 | 1].cnt[i]);
    }

    void evel(int u, int *tag) {
        V<int> tmp(22, 0);
        FOR(i, 1, 20) tmp[tag[i]] += tr[u].cnt[i];

        FOR(i, 1, 20) tr[u].cnt[i] = tmp[i];

        /*

        tr[u].tag[i] = v 的含义是：在当前这个节点（子树）中，原本数值为i 的数，经过之前的若干次修改，现在变成了v。
        map_arr[v] = w的含义是：父节点下发了一个新指令，要求把当前子树中现在是v 的数，全部变成w。

        为什么要用 tr[u].tag[i] = map_arr[tr[u].tag[i]]

        这其实是一个函数复合的过程。
        假设一个数字经历了两步变化：
        第一步（原有标记）：数字i通过当前节点的标记变成了v。 即
        第二步（新下发标记）：下发的指令要求把v变成w。


        */
        FOR(i, 1, 20) tr[u].tag[i] = tag[tr[u].tag[i]];
    }

    void pushdown(int u) {
        bool f = false;
        FOR(i, 1, 20) {
            if (tr[u].tag[i] != i) {
                f = 1;
                break;
            }
        }

        if (f) {
            evel(u << 1, tr[u].tag);
            evel(u << 1 | 1, tr[u].tag);
            FOR(i, 1, 20) tr[u].tag[i] = i;
        }
    }

    void build(int u, int l, int r, V<int> &w) {
        tr[u].l = l, tr[u].r = r;
        FOR(i, 1, 20) tr[u].tag[i] = i;
        FOR(i, 1, 20) tr[u].cnt[i] = 0;
        if (l == r) {
            tr[u].cnt[w[l]] = 1;
            RE;
        }

        int mid = (l + r) / 2;
        build(u << 1, l, mid, w), build(u << 1 | 1, mid + 1, r, w);
        pushup(u);
    }

    void modify(int u, int l, int r, int x, int y) {
        if (x == y) RE;
        if (tr[u].l > r || tr[u].r < l) RE;
        if (tr[u].cnt[x] == 0) RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            int tmp[22];
            FOR(i, 1, 20) tmp[i] = i;
            tmp[x] = y;
            evel(u, tmp);
            RE;
        }

        pushdown(u);
        modify(u << 1, l, r, x, y);
        modify(u << 1 | 1, l, r, x, y);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) {
            int ans = 0;
            FOR(i, 1, 20) ans += i * tr[u].cnt[i];
            return ans;
        }
        pushdown(u);
        return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    A.build(1, 1, n, w);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            A.modify(1, l, r, x, y);
        } else {
            int l, r;
            cin >> l >> r;
            cout << A.query(1, l, r) << endl;
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