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
    map<int, int>mp;
    for (auto& x : w)cin >> x, mp[x]++;

    if (n == 1) {
        cout << 1 << endl;
        RE;
    }

    int x = 0;

    FOR (i, 1, n - 1) {
        x = __gcd (x, abs (w[i] - w[i - 1]));
    }

    int ans = 0, mx = *max_element (ALL (w));

    FOR (i, 0, n - 1) {
        ans += (mx - w[i]) / x;
    }

    int t = 0;

    while (1) {
        if (t == n)break;
        if (!mp[mx - t * x]) {
            break;
        }
        t++;
    }

    ans += t;


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