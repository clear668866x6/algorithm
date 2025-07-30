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

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    V<int>f (2e5 + 10, 1e18), pre (2e5 + 10, 0);

    V<PII>c;

    int mx = 2e5 + 2;

    for (int i = 1;;i++) {
        int t = (i + 1) * i / 2;
        if (t > mx)break;
        c.eb (t, i);
    }

    f[0] = 0;
    FOR (i, 0, c.sz - 1) {
        FOR (j, c[i].fi, mx) {
            if (f[j - c[i].fi] != 1e18) {
                int nw = f[j - c[i].fi] + (j - c[i].fi != 0) + c[i].se;
                if (nw < f[j]) {
                    f[j] = nw;
                    pre[j] = c[i].se;
                }
            }
        }
    }


    function<void (void)>solve = [&] () {
        int x;
        cin >> x;
        V<int>ans;
        while (x > 0) {
            int l = pre[x];
            if (!l)break;
            ans.eb (l);
            x -= ((l + 1) * l / 2);
        }

        string res = "";

        FOR (i, 0, ans.sz - 1) {
            res += string (ans[i], '1');
            if (i < ans.sz - 1) {
                res += '0';
            }
        }
        cout << res << endl;

        };

    while (Task--) {
        solve ();
    }

    return 0;
}