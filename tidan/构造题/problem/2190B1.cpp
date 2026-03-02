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

    set<int> idx;

    V<int> sr(n + 2, 0), sl(n + 2, 0);

    FORD(i, 1, n) {
        sl[i] = sl[i + 1];
        sr[i] = sr[i + 1];
        if (s[i] == '(') {
            sl[i]++;
            idx.insert(i);
        } else {
            sr[i]++;
        }
    }

    int ans = -1, cur = 0, curl = 0, curr = 0;

    FOR(i, 1, n - 1) {
        curl += (s[i] == '('), curr += (s[i] == ')');
        if (i > 1) {
            if (s[i] == ')') {
                auto it = idx.upper_bound(i);
                cur++;
                if (it != idx.end()) {
                    if (sr[*it] >= cur) {
                        int t = i + cur;
                        int rel = sl[1] - curl - 1;
                        int rer = (sr[1] - curr - cur);
                        ans = max(ans, t + min(rel, rer) * 2);
                    }
                }
                cur--;
            }
        }
        if (s[i] == '(')
            cur++;
        else
            cur--;
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
