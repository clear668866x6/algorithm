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

string ans;
int mx;

void dfs(int a, int b) {
    if (!a && !b) {
        int tot = 0;
        FOR(len, 0, sz(ans) - 1) {
            FOR(i, 0, sz(ans) - 1) {
                if (i + len >= sz(ans)) break;
                int p = 0;
                int c0 = 0, c1 = 0;
                FOR(j, i, i + len) {
                    if (ans[j] == '0') c0++;
                    if (ans[j] == '1') c1++;
                }

                if (!p && c0) p++;
                if (p == 1 && c1) p++;
                tot += p;
            }
        }
        mx = max(mx, tot);
        if (tot == 158) cout << ans << ' ' << tot << endl;
        RE;
    }

    if (a) {
        ans += '0';
        dfs(a - 1, b);
        ans.pop_back();
    }
    if (b) {
        ans += '1';
        dfs(a, b - 1);
        ans.pop_back();
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    dfs(a, b);
    cout << "mx= " << mx;
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