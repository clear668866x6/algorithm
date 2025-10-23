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

    V<array<int, 3>>w (m);

    FOR (i, 0, m - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        w[i] = { a,b,c };
    }

    int q;
    cin >> q;

    V<V<int>>query (q);

    FOR (i, 0, q - 1) {
        int t, x;
        cin >> t;
        while (t--) {
            cin >> x;
            query[i].eb (x);
        }
    }

    int l = 0, r = 1e12;

    function<bool (int)>check = [&] (int x) {
        V<int>p (n + 1, 0);
        function<int (int)>find = [&] (int x) {
            if (x != p[x])p[x] = find (p[x]);
            return p[x];
            };

        FOR (i, 1, n)p[i] = i;

        FOR (i, 0, m - 1) {
            auto [a, b, c] = w[i];
            if (c <= x) {
                if (find (a) != find (b)) {
                    p[find (a)] = find (b);
                }
            }
        }

        FOR (i, 0, q - 1) {
            int t = query[i].sz;
            FOR (j, 1, t - 1) {
                if (find (query[i][j]) != find (query[i][j - 1])) {
                    return false;
                }
            }
        }
        return true;

        };

    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (check (mid))r = mid;
        else l = mid;
    }

    cout << r << endl;

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