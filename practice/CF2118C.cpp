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
    V<int>w (n);
    for (auto& x : w)cin >> x;

    V<int>b (64, 0);

    int ans = 0;

    FOR (i, 0, n - 1) {
        FOR (j, 0, 62) {
            if (w[i] >> j & 1) {
                b[j]++;
                ans++;
            }
        }
    }

    FOR (i, 0, 62) {
        if (b[i] != n && k > 0) {
            if (k - (1LL << i) * (n - b[i]) >= 0) {
                k -= (1LL << i) * (n - b[i]);
                ans += (n - b[i]);
            } else {
                int t = n - b[i];
                while (k > 0) {
                    k -= (1LL << i);
                    if (k >= 0) {
                        t--;
                        ans++;
                    }
                }
            }
        }
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