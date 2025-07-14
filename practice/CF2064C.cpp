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

void solve () {
    int n;
    cin >> n;

    V<int>w (n + 1, 0), s1 (n + 1, 0), s2 (n + 2, 0);

    FOR (i, 1, n)cin >> w[i];
    FOR (i, 1, n) {
        if (w[i] > 0) {
            s1[i] = s1[i - 1] + w[i];
        } else {
            s1[i] = s1[i - 1];
        }
    }

    FORD (i, 1, n) {
        if (w[i] < 0) {
            s2[i] = s2[i + 1] + abs (w[i]);
        } else {
            s2[i] = s2[i + 1];
        }
    }

    int ans = 0;

    FOR (i, 1, n) {
        ans = max (ans, s1[i] + s2[i]);
    }

    cout << ans << endl;


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