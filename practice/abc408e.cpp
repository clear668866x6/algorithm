#include <bits/stdc++.h>
#include <functional>
#include <numeric>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    int n, m;

    cin >> n >> m;

    V<array<int, 3>> w(m + 1);

    FOR(i, 1, m) { cin >> w[i].at(0) >> w[i].at(1) >> w[i].at(2); }

    V<int> p(n + 1, 0);

    function<int(int)> find = [&](int x) {
        if (x != p[x])
            return p[x] = find(p[x]);
        return p[x];
    };

    function<int(int)> check = [&](int x) {
        FOR(i, 1, n) p[i] = i;
        FOR(i, 1, m) {
            if ((w[i].back() | x) == x) {
                int a = find(w[i].at(0)), b = find(w[i].at(1));
                if (a != b) {
                    p[a] = b;
                }
            }
        }
        if (find(1) == find(n))
            return 1;
        return 0;
    };

    int ans = 0;

    FORD(i, 0, 30) {
        if (!check((ans | ((1LL << i) - 1)))) {
            ans |= (1LL << i);
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