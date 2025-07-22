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
    V<int>w (n);
    int tot = 0;
    for (auto& x : w)cin >> x, tot += x;

    if (tot & 1) {
        cout << 0 << endl;
        RE;
    }

    tot /= 2;

    V<int>f (tot + 1, 0);
    f[0] = 1;

    FOR (i, 0, n - 1) {
        FORD (j, w[i], tot) {
            f[j] |= f[j - w[i]];
        }
    }

    if (!f[tot]) {
        cout << 0 << endl;
        RE;
    }

    cout << 1 << endl;

    FOR (i, 0, n - 1) {
        if (w[i] & 1) {
            cout << (i + 1) << endl;
            RE;
        }
    }

    FOR (k, 0, 32) {
        FOR (i, 0, n - 1) {
            if (w[i] >> k & 1) {
                cout << (i + 1) << endl;
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