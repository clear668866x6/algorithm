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
    int n, q;
    string a, b;
    cin >> n >> a >> b >> q;

    int ans = 0;

    FOR (i, 0, n - 1) {
        ans += (a[i] == '1' && b[i] == '1');
    }

    unordered_set<int>sa1, sa0, sb1, sb0;
    V<int>a0, b0;

    FOR (i, 0, n - 1) {
        if (a[i] == '1')sa1.insert (i);
        if (a[i] == '0')a0.eb (i), sa0.insert (i);
        if (b[i] == '1')sb1.insert (i);
        if (b[i] == '0')b0.eb (i), sb0.insert (i);
    }

    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        l--, r--;
        if (c == 'A') {
            int L = lower_bound (ALL (a0), l) - a0.begin ();
            int R = upper_bound (ALL (a0), r) - a0.begin () - 1;
            FOR (i, L, R) {
                if (sa1.count (a0[i]))continue;
                sa0.erase (a0[i]);
                sa1.insert (a0[i]);
                if (sb1.count (a0[i]))ans++;
            }
        } else {
            int L = lower_bound (ALL (b0), l) - b0.begin ();
            int R = upper_bound (ALL (b0), r) - b0.begin () - 1;
            FOR (i, L, R) {
                if (sb1.count (b0[i]))continue;
                sb0.erase (b0[i]);
                sb1.insert (b0[i]);
                if (sa1.count (b0[i]))ans++;
            }
        }
        cout << ans << endl;
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