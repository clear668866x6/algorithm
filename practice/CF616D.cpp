#include <algorithm>
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
    int n, k;
    cin >> n >> k;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    int mx = *ranges::max_element(w);
    V<int> mp(mx + 1, 0);
    int c = 0;

    V<int> L(n + 1, 0);
    int j = 1;
    FOR(i, 1, n) {
        if (!mp[w[i]]) {
            c++;
        }
        mp[w[i]]++;
        while (j <= i && c > k) {
            mp[w[j]]--;
            if (!mp[w[j]]) {
                c--;
            }
            j++;
        }
        if (c == k) L[i] = j;
    }

    int ans = 0, ansl = 1, ansr = n;

    FOR(i, 1, n) {
        if (L[i] && i - L[i] + 1 > ans) {
            ans = i - L[i] + 1;
            ansl = L[i], ansr = i;
        }
    }

    cout << ansl << ' ' << ansr << endl;
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