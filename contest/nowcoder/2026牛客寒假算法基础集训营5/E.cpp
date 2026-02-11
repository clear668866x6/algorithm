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
    int n, p;
    cin >> n >> p;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];
    V<int> s(n + 1, 0);
    map<int, V<int>> mp;
    FOR(i, 1, n) s[i] = (s[i - 1] + w[i]) % p, mp[s[i]].eb(i);
    mp[0].eb(0);

    int ans = 0, ansl = 0, ansr = 0;
    FOR(i, 1, n) {
        if (w[i] > ans) {
            ans = w[i];
            ansl = ansr = i - 1;
        }
    }

    int mn = 0, idx = 0;
    set<int> st;
    st.insert(0);
    st.insert(s[1]);

    FOR(i, 2, n) {
        auto it = st.upper_bound(s[i]);
        if (it != st.end()) {
            int t = mp[*it][0];
            int pp = (s[i] - *it + p) % p;
            if (pp > ans) {
                ans = pp;
                ansl = t, ansr = i - 1;
            }
        }
        if (mn <= s[i]) {
            int pp = (s[i] - mn + p) % p;
            if (pp > ans) {
                ans = pp;
                ansl = idx, ansr = i - 1;
            }
        }
        if (s[i] < mn) {
            mn = s[i];
            idx = i - 1;
        }
        st.insert(s[i]);
    }

    cout << ansl << ' ' << ansr << ' ' << ans;
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