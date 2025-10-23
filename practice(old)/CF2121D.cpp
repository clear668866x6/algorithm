#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
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
//反证法可以证明这种方法是可以的。
void solve () {
    int n;
    cin >> n;
    V<int>a (n + 1, 0), b (n + 1, 0);

    FOR (i, 1, n)cin >> a[i];
    FOR (i, 1, n)cin >> b[i];

    V<PII>ans;

    FOR (i, 1, n) {
        FOR (j, 1, n - i) {
            if (b[j] > b[j + 1]) {
                swap (b[j + 1], b[j]);
                ans.eb (2, j);
            }
            if (a[j] > a[j + 1]) {
                swap (a[j], a[j + 1]);
                ans.eb (1, j);
            }
        }
    }

    FOR (i, 1, n) {
        if (a[i] > b[i]) {
            swap (a[i], b[i]);
            ans.eb (3, i);
        }
    }

    cout << ans.sz << endl;
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }


}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}