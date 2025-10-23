#include <bits/stdc++.h>
#include <functional>
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

int mod = 1e9 + 7;

struct Comb {
    static constexpr int N = 1010;
    int f[N][N];

    void init() {
        FOR(i, 0, 1000) {
            FOR(j, 0, i) {
                if (!j)
                    f[i][j] = 1;
                else
                    f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
            }
        }
    }

    int C(int x, int y) {
        return f[x][y];
    }
} A;

void solve() {
    int n, k;
    cin >> n >> k;
    V<int> w(n + 1, 0);
    map<int, int> mp, mp2;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;
    sort(ALL(w));

    FOR(i, n - k + 1, n) {
        mp2[w[i]]++;
    }

    int ans = 1;

    for (auto [x, y] : mp2) {
        (ans *= (A.f[mp[x]][y])) %= mod;
    }

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    A.init();
    while (Task--) {
        solve();
    }

    return 0;
}
