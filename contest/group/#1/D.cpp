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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int mn = min ({ a,b,c,d }) - 1;
    a -= mn, b -= mn, c -= mn, d -= mn;

    FOR (k, 1, 20) {
        if (k & 1) {
            if (c > 0) {
                b--;
                d--;
                if (b <= 0 || d == 0) {
                    cout << "Gellyfish" << endl;
                    RE;
                }
            }
        } else {
            if (d > 0) {
                a--;
                c--;
                if (a <= 0 || c == 0) {
                    cout << "Flower" << endl;
                    RE;
                }
            }
        }
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