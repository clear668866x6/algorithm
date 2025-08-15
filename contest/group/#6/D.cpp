#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    s = ' ' + s;

    int ans = k;

    string p1, p2, p3;
    p1 = "RGB";
    p2 = "GB";
    p3 = "B";
    FOR(i, 1, k) {
        p1 += "RGB";
        p2 += "RGB";
        p3 += "RGB";
    }

    FOR(i, 1, n) {
        if (i + k - 1 <= n) {
            int c1 = 0, c2 = 0, c3 = 0, p = 0;
            FOR(j, i, i + k - 1) {
                if (p1[j - i] != s[j]) {
                    c1++;
                }
                if (p2[j - i] != s[j]) c2++;
                if (p3[j - i] != s[j]) c3++;
            }
            ans = min({ans, c1, c2, c3});
        }
    }
    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
