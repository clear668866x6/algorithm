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
    cin >> n;

    set<string> s;

    auto check = [&](string &p) {
        int tot = 0;
        if (!(p[0] == '(' && p[sz(p) - 1] == ')')) {
            return false;
        }
        for (auto x : p) {
            tot += (x == '(');
            tot -= (x == ')');
        }
        if (tot != 0) return false;

        stack<char> st;

        FOR(i, 0, sz(p) - 1) {
            if (p[i] == '(') {
                st.push('(');
            } else {
                if (!sz(st)) {
                    return false;
                }
                st.pop();
            }
        }

        if (sz(st)) return false;
        return true;
    };

    function<void(int, string)> dfs = [&](int u, string p) {
        if (u == n + 1) {
            if (check(p)) {
                s.insert(p);
            }
            RE;
        }

        dfs(u + 1, p + '(');
        dfs(u + 1, p + ')');
    };

    if (!(n & 1)) {
        dfs(1, "");
        for (auto x : s) {
            cout << x << endl;
        }
    }
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