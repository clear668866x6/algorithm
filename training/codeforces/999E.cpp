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

struct Targin {
    static constexpr int N = 2e4 + 10;
    int dfn[N], low[N], id[N];
    int stk[N], scc_cnt, scc_size[N];
    bool in_stk[N];
    int tmp, top;
    V<int> g[N];

    void add(int a, int b) {
        tmp = top = 0;
        g[a].eb(b);
    }

    void targin(int u) {
        dfn[u] = low[u] = ++tmp;
        stk[++top] = u, in_stk[u] = 1;

        for (auto j : g[u]) {
            if (!dfn[j]) {
                targin(j);
                low[u] = min(low[u], low[j]);
            } else if (in_stk[j]) {
                low[u] = min(low[u], dfn[j]);
            }
        }

        if (low[u] == dfn[u]) {
            int y;
            scc_cnt++;
            do {
                y = stk[top--];
                in_stk[y] = 0;
                id[y] = scc_cnt;
                scc_size[scc_cnt]++;
            } while (y != u);
        }
    }

} A;

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        A.add(a, b);
    }

    FOR(i, 1, n) {
        if (!A.dfn[i]) {
            A.targin(i);
        }
    }

    V<int> d(n + 1, 0);

    FOR(i, 1, n) {
        for (auto j : A.g[i]) {
            if (A.id[i] != A.id[j]) {
                d[A.id[j]]++;
            }
        }
    }

    int ans = 0;

    FOR(i, 1, A.scc_cnt) {
        if (d[i] == 0 && i != A.id[s]) {
            ans++;
        }
    }

    cout << ans;
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