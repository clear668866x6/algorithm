#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
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
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    V<int> p1(n + 1, 0), p2(n + 1, 0), p3(n + 1, 0);
    FOR(i, 1, n) {
        p1[i] = p1[i - 1] + (s[i] == '1');
        p2[i] = p2[i - 1] + (s[i] == '2');
        p3[i] = p3[i - 1] + (s[i] == '3');
    }

    int ans = 0;

    FOR(l, 1, n) {
        FOR(r, l, n) {
            int c1 = p1[r] - p1[l - 1];
            int c2 = p2[r] - p2[l - 1];
            int c3 = p3[r] - p3[l - 1];
            if (c1 == c2 && c1 == c3) {
                ans++;
            }
        }
    }
    cout << ans;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}