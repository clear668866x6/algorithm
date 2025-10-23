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
    string s;
    cin >> n >> s;
    V<int>a (n);
    FOR (i, 0, n - 1)a[i] = s[i] - '0';

    int c1 = 0, c2 = 0, ans = 0;

    V<int>b (n, 0), c (n, 0);

    FOR (i, 0, n - 1) {
        if (i & 1) {
            b[i] = 1, c[i] = 0;
        } else {
            b[i] = 0, c[i] = 1;
        }
    }

    int state = 0;

    FOR (i, 0, n - 1) {
        if ((state ^ a[i]) != b[i]) {
            state = 1;
            c1++;
        } else {
            state = 0;
        }
    }

    if (state)c1 = 1e18;

    state = 0;

    FOR (i, 0, n - 1) {
        if ((state ^ a[i]) != c[i]) {
            state = 1;
            c2++;
        } else {
            state = 0;
        }
    }
    if (state)c2 = 1e18;

    ans = min (c1, c2);

    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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