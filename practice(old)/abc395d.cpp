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

    unordered_map<int, set<int>>w;
    unordered_map<int, int>mp, c, d;

    FOR (i, 1, n)w[i].insert (i), mp[i] = i, c[i] = i, d[i] = i;

    while (m--) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            w[mp[a]].erase (a);
            mp[a] = c[b];
            w[mp[a]].insert (a);
        } else if (op == 2) {
            cin >> a >> b;
            swap (d[c[a]], d[c[b]]);
            swap (c[d[c[a]]], c[d[c[b]]]);
        } else {
            cin >> a;
            cout << d[mp[a]] << endl;
        }
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