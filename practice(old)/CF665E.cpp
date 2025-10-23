#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
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

struct Tire {
    static constexpr int N = 1e6 + 10;
    struct E {
        int ch[2];
        int siz;
    } tr[N * 31];
    int idx;

    Tire() {
        idx = 2;
    }

    void insert(int x) {
        int u = 1;
        FORD(i, 0, 30) {
            int v = x >> i & 1;
            if (!tr[u].ch[v]) tr[u].ch[v] = idx++;
            u = tr[u].ch[v];
            tr[u].siz++;
        }
    }

    i64 query(int x, int k) {
        int u = 1;
        i64 tot = 0;
        FORD(i, 0, 30) {
            int a = x >> i & 1, b = k >> i & 1;
            if (!b) {
                tot += tr[tr[u].ch[a ^ 1]].siz;
            }
            u = tr[u].ch[a ^ b];
        }
        tot += tr[u].siz;
        return tot;
    }

} A;

void solve() {
    int n, k;
    cin >> n >> k;
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    int s = 0;
    i64 ans = 0;
    A.insert(0);
    FOR(i, 1, n) {
        s ^= a[i];
        ans += A.query(s, k);
        A.insert(s);
    }

    cout << ans << endl;
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