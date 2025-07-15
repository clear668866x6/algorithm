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
    string w;
    cin >> n >> w;
    w = ' ' + w;
    V<int>suml (n + 1, 0), sumr (n + 1, 0);

    FOR (i, 1, n) {
        suml[i] = suml[i - 1] + (w[i] == '0');
        sumr[i] = sumr[i - 1] + (w[i] == '1');
    }

    double ans = 1e18, res = 0;

    FOR (i, 0, n) {
        int sl = i, sr = n - i;
        int tl = suml[i], tr = sumr[n] - sumr[i];
        if (tl >= (sl + 1) / 2 && tr >= (sr + 1) / 2) {
            if (fabs (1. * n / 2 - i) < ans) {
                ans = fabs (1. * n / 2 - i);
                res = i;
            }
        }
    }

    cout << res << endl;


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