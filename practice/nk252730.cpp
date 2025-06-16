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
    int n, m, k, b;
    cin >> n >> m >> k >> b;

    V<int>h (n), a (n);
    for (auto& x : h)cin >> x;
    for (auto& x : a)cin >> x;

    FOR (i, 0, n - 1) {
        int t1 = m - 1;
        if (t1 <= (k - h[i]) / a[i]) {
            cout << (h[i] + t1 * a[i]) << ' ';
        } else {
            t1--;
            int p = (t1 - (k - h[i]) / a[i]);
            if (((k - b) / a[i]) == 0) {
                cout << b << ' ';
            } else {
                int pp = p % ((k - b) / a[i] + 1);
                cout << (b + pp * a[i]) << ' ';
            }
        }
    }
    cout << endl;
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