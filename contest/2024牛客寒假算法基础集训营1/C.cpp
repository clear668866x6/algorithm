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
    int n, q, tc;
    cin >> n >> q >> tc;
    V<int>t (n);
    for (auto& x : t)cin >> x;

    sort (ALL (t));

    V<int>s (n + 2, 0);

    int sm = 0;

    FOR (i, 1, n)s[i] = s[i - 1] + t[i - 1], sm += s[i];

    while (q--) {
        int M;
        cin >> M;
        int l = -1, r = n + 1;

        function<bool (int)>check = [&] (int x) {
            int p = sm;
            int pp = p + (n - x) * tc;
            return pp - sm <= M;
            };

        while (l + 1 != r) {
            int mid = l + r >> 1;
            if (check (mid))r = mid;
            else l = mid;
        }
        cout << s[r] + tc << endl;
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