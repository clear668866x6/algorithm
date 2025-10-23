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

struct Prime {
    V<int>primes, vis;
    int cnt;

    void init (int x) {
        primes.resize (x + 10), vis.resize (x + 10);
        cnt = 0;

        for (int i = 2; i <= x;i++) {
            if (!vis[i])primes[cnt++] = i;
            for (int j = 0;i * primes[j] <= x;j++) {
                vis[i * primes[j]] = 1;
                if (i % primes[j] == 0)break;
            }
        }
    }
}A;

void solve () {
    int n;
    cin >> n;

    V<int>w (n);
    for (auto& x : w)cin >> x;

    sort (ALL (w));

    int tot = 0, tmp = 0;

    FOR (i, 0, n - 1) {
        tot += (w[i] - 2);
        tmp += (A.primes[i] - 2);
    }

    if (tot >= tmp) {
        cout << 0 << endl;
        RE;
    }

    FOR (i, 0, n - 1) {
        tot -= (w[i] - 2);
        tmp -= (A.primes[n - i - 1] - 2);
        if (tot >= tmp) {
            cout << i + 1 << endl;
            RE;
        }
    }

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;
    A.init (1e7);
    while (Task--) {
        solve ();
    }

    return 0;
}
