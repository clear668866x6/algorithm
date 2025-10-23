#include <bits/stdc++.h>
#include <cstring>
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

struct Shuweidp {
    static constexpr int N = 30;

    int f[N][N];
    V<int> num;

    int dfs(int u, int lst, bool lim) {
        if (u == sz(num)) return lst != 10;
        if (!lim && ~f[u][lst]) return f[u][lst];
        int res = 0;
        FOR(i, 0, (lim ? num[u] : 9)) {
            if (lst == 10) {
                if (!i) {
                    res = (res + dfs(u + 1, 10, lim && num[u] == i));
                } else {

                    res = (res + dfs(u + 1, i, lim && num[u] == i));
                }
            } else {
                if (abs(lst - i) < 2) continue;
                res = (res + dfs(u + 1, i, lim && num[u] == i));
            }
        }
        if (!lim) f[u][lst] = res;
        return res;
    }

    int work(int x) {
        memset(f, -1, sizeof f);
        if (!x) return 0;
        num.clear();
        while (x) {
            num.eb(x % 10);
            x /= 10;
        }
        reverse(ALL(num));

        return dfs(0, 10, 1);
    }

} A;

void solve() {
    int a, b;
    cin >> a >> b;

    cout << (A.work(b) - A.work(a - 1));
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