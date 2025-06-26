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
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 1 << endl;
        cout << a << endl;
        RE;
    }

    if (b > 0) {
        FOR2 (i, 3, 1000, 2) {
            int x = i * a - b - (i - 1) / 2 * (b + 1);
            if (x >= 0) {
                cout << i << endl;
                FOR (j, 1, (i - 1) / 2) {
                    cout << 1 << ' ';
                }
                cout << b << ' ';
                FOR (j, 1, (i - 1) / 2 - 1)cout << b << ' ';
                cout << (b + x) << endl;
                RE;
            } else {
                cout << i << endl;
                FOR (j, 1, (i - 1) / 2 - 1) {
                    cout << 1 << ' ';
                }
                cout << 1 + x << ' ';
                cout << b << ' ';
                FOR (j, 1, (i - 1) / 2)cout << b << ' ';
                RE;
            }
        }
    } else {
        FOR2 (i, 3, 1000, 2) {
            int x = i * a - b - (i - 1) / 2 * b;
            if (x <= 0) {
                cout << i << endl;
                cout << b + x << ' ';
                FOR (j, 1, (i - 1) / 2 - 1)cout << b << ' ';
                cout << b << ' ';
                FOR (j, 1, (i - 1) / 2)cout << 0 << ' ';
                cout << endl;
                RE;
            } else {
                cout << i << endl;
                FOR (j, 1, (i - 1) / 2)cout << b << ' ';
                cout << b << ' ';
                FOR (j, 1, (i - 1) / 2 - 1)cout << 0 << ' ';
                cout << x << endl;
                RE;
            }
        }
    }


}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}