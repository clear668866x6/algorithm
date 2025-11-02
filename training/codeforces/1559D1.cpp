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

struct DSU {
    static constexpr int N = 1e4 + 10;
    int p[N], siz[N];

    DSU() {
        memset(p, 0, sizeof p);
        memset(siz, 0, sizeof siz);
        FOR(i, 1, N - 10) p[i] = i, siz[i] = 1;
    }

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

} A, B;

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    FOR(i, 1, m1) {
        int a, b;
        cin >> a >> b;
        a = A.find(a), b = A.find(b);
        if (a != b) {
            A.p[a] = b;
        }
    }

    FOR(i, 1, m2) {
        int a, b;
        cin >> a >> b;
        a = B.find(a), b = B.find(b);
        if (a != b) {
            B.p[a] = b;
        }
    }

    set<array<int, 2>> s;

    FOR(l, 1, n) {
        FOR(r, l + 1, n) {
            if (A.find(l) != A.find(r) && B.find(l) != B.find(r)) {
                A.p[A.find(l)] = A.find(r);
                s.insert({l, r});
                B.p[B.find(l)] = B.find(r);
            }
        }
    }

    cout << sz(s) << endl;
    for (auto [x, y] : s) cout << x << ' ' << y << endl;
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