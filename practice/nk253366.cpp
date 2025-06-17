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

struct BitTree {
    V<int>tr;
    int n;

    BitTree (int x) {
        tr.resize (x + 10);
        n = x;
    }

    void add (int x, int c) {
        for (int i = x;i < n;i += lowbit (i))tr[i] = max (tr[i], c);
    }

    int query (int x) {
        int ans = 0;
        for (int i = x;i;i -= lowbit (i))ans = max (tr[i], ans);
        return ans;
    }

};

void solve () {
    int n;
    cin >> n;
    V<int>a (n + 1, 0), b (n + 1, 0), c (n + 1, 0);

    FOR (i, 1, n)cin >> a[i];
    FOR (i, 1, n)cin >> b[i];

    FOR (i, 1, n) {
        c[b[i]] = i;
    }

    FOR (i, 1, n) {
        a[i] = c[a[i]];
    }

    BitTree A (4 * n + 1);

    int ans = 0;

    FOR (i, 1, n) {
        int t = A.query (a[i] - 1) + 1;
        A.add (a[i], t);
        ans = max (ans, t);
    }

    cout << (n - ans) << endl;

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