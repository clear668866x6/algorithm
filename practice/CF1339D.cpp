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

    V<int> ans(n + 1, 0);

    set<int> st[2];

    FOR(i, 0, n - 1) {
        if (s[i] == '1') {
            st[1].insert(i);
        } else {
            st[0].insert(i);
        }
    }

    int num = 1;

    FOR(i, 0, n - 1) {
        if (!ans[i]) {
            ans[i] = num;
            int t = (s[i] - '0') ^ 1;
            int idx = i;
            while (st[t].upper_bound(idx) != st[t].end()) {
                auto it = st[t].upper_bound(idx);
                ans[*it] = num;
                idx = *it;
                st[t].erase(it);
                t ^= 1;
            }
            num++;
        }
    }

    cout << num - 1 << endl;
    FOR(i, 0, n - 1) cout << ans[i] << " \n"[i == n - 1];
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
