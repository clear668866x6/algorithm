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

    if (n & 1) {
        if (n <= 26) {
            cout << -1 << endl;
            RE;
        }
        cout << 1 << ' ';
        FOR (i, 2, 5)cout << i << ' ' << i << ' ';
        cout << "1 ";
        FOR (i, 6, 11)cout << i << ' ' << i << ' ';
        cout << "13 12 12 1 13 ";
        FOR (i, 14, (n - 27) / 2 + 13)cout << i << ' ' << i << ' ';
        cout << endl;
    } else {
        FOR (i, 1, n / 2) {
            cout << i << ' ' << i << ' ';
        }
        cout << endl;
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