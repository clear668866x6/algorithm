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
    int n, q;
    cin >> n >> q;

    V<int> p(n + 1, 0);

    FOR(i, 1, n) p[i] = i;

    V<int> w(n + 1, 0), rank(n + 1, 0), c(n + 1, 0);

    function<int(int)> find = [&](int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    };

    function<void(int, int)> uni = [&](int a, int b) -> void {
        a = find(a), b = find(b);
        if (a == b) RE;
        if (rank[a] < rank[b]) {
            p[a] = b;
            w[b] += w[a];
        } else if (rank[a] > rank[b]) {
            p[b] = a;
            w[a] += w[b];
        } else {
            p[b] = a;
            w[a] += w[b];
        }
    };

    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            int a = find(x), b = find(y);
            uni(a, b);
        } else if (op == 2) {
            cin >> x;
            int t = find(x);
            if (!c[x]) {
                c[x]++;
                w[t]++;
            } else {
                c[x]--;
                w[t]--;
            }
        } else {
            cin >> x;
            if (w[find(x)]) {
                Yes;
            } else {
                No;
            }
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