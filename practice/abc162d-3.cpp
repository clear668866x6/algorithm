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

    V<int> prer(n + 1, 0), preg(n + 1, 0), preb(n + 1, 0);

    set<int> s1, s2, s3;

    FOR(i, 1, n) {
        if (s[i] == 'R') {
            s1.insert(i);
        } else if (s[i] == 'G') {
            s2.insert(i);
        } else {
            s3.insert(i);
        }
    }

    FOR(i, 1, n) prer[i] = prer[i - 1] + (s[i] == 'R');
    FOR(i, 1, n) preg[i] = preg[i - 1] + (s[i] == 'G');
    FOR(i, 1, n) preb[i] = preb[i - 1] + (s[i] == 'B');

    int ans = 0;

    FOR(l, 1, n) {
        FOR(r, l + 1, n) {
            if (s[l] == s[r]) continue;
            int c = 2 * r - l;
            for (auto x : {'R', 'G', 'B'}) {
                if (x != s[l] && x != s[r]) {
                    if (x == 'R') {
                        ans += prer[n] - prer[r];
                        if (c <= n && s1.count(c)) {
                            ans--;
                        }
                    } else if (x == 'G') {
                        ans += preg[n] - preg[r];
                        if (c <= n && s2.count(c)) {
                            ans--;
                        }
                    } else {
                        ans += preb[n] - preb[r];
                        if (c <= n && s3.count(c)) {
                            ans--;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
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