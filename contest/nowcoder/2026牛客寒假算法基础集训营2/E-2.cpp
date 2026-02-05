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

int w[100][100];
int n, cnt;

array<int, 2> get(int x) {
    return {(x - 1) / n + 1, (x - 1) % n + 1};
}

void dfs(int u) {
    if (get(u) == array<int, 2>{n, n}) {
        set<int> s1, s2, s3;
        FOR(i, 0, n - 1) s3.insert(i);
        FOR(i, 1, n) {
            int tot = 0;
            FOR(j, 1, n) {
                tot += w[i][j];
            }
            s1.insert(tot);
        }
        FOR(j, 1, n) {
            int tot = 0;
            FOR(i, 1, n) {
                tot += w[i][j];
            }
            s2.insert(tot);
        }

        if (sz(s1) == sz(s2) && s1 == s3) {
            FOR(i, 1, n) {
                FOR(j, 1, n) {
                    cout << w[i][j];
                }
                cout << endl;
            }
            cout << endl;
            cnt++;
        }
        if (cnt == 100) exit(0);
        RE;
    }
    auto [x, y] = get(u);
    w[x][y] = 1;
    dfs(u + 1);
    w[x][y] = 0;
    dfs(u + 1);
}

void solve() {
    cin >> n;
    dfs(1);
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