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
    int n, k;
    cin >> n >> k;

    V<int>a (n), b (n);

    for (auto& x : a)cin >> x;
    for (auto& x : b)cin >> x;
    int ans = 0;

    V<int>visa (n, 0), visb (n, 0);
    FOR (i, 0, n - 1) {
        ans += max (a[i], b[i]);
        if (a[i] > b[i]) {
            visa[i] = 1;
        } else {
            visb[i] = 1;
        }
    }

    V<int>p;

    FOR (i, 0, n - 1) {
        if (!visa[i]) {
            p.eb (a[i]);
        } else {
            p.eb (b[i]);
        }
    }

    sort (ALL (p), greater ());

    FOR (i, 0, k - 2) {
        ans += p[i];
    }
    cout << (ans + 1) << endl;

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