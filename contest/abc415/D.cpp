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
    int n, m;
    cin >> n >> m;

    struct E {
        int a, b, dif;
        bool operator<(const E& t)const {
            if (dif == t.dif)return a < t.a;
            return dif < t.dif;
        }
    };

    V<E>w (m);

    FOR (i, 0, m - 1)cin >> w[i].a >> w[i].b, w[i].dif = w[i].a - w[i].b;

    sort (ALL (w));

    int i = 0, ans = 0;

    while (i < m) {
        if (n - w[i].a >= 0) {
            int l = 0, r = 1e18;
            while (l + 1 != r) {
                int mid = l + r >> 1;
                if (n - (i128)mid * w[i].dif <= w[i].a)r = mid;
                else l = mid;
            }
            if (n - r * w[i].dif == w[i].a)r++;
            ans += r;
            // cout << i << ' ' << r << ' ' << (n - r * w[i].dif) << ' ' << w[i].dif << endl;
            n -= r * w[i].dif;
            i++;
        } else {
            i++;
        }
    }

    cout << ans;

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