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
    int n, s;
    cin >> n >> s;
    int len = to_string (n).sz;
    string t = to_string (n);
    int ans = 1e18;
    t = ' ' + t;

    int tt = 0;

    FOR (i, 1, len){
        tt += (t[i] - '0');
    }

    if (tt <= s){
        cout << 0 << endl;
        RE;
    }

    FOR (i, 1, len){
        int p = pow (10, len - i + 1);
        int tmp = n + (p - n % p);
        string y = to_string (tmp);
        int tot = 0;
        for (auto x : y){
            tot += (x - '0');
        }
        if (tot <= s){
            ans = min (ans, tmp - n);
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