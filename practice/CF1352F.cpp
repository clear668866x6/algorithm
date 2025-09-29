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
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    if (n1 & 1) {
        int t = (n1 + 1) / 2;
        string ans;
        while (t--) {
            ans += "10";
        }
        string p;
        while (n2--) {
            p += '1';
        }
        ans = p + ans;

        while (n0--) {
            ans += '0';
        }
        cout << ans << endl;
    } else {
        int t = (n1 + 1) / 2;
        string ans;
        while (t--) {
            ans += "10";
        }
        string p;
        while (n2--) {
            p += '1';
        }
        ans = p + ans;

        while (n0--) {
            ans += '0';
        }
        if (n1) {
            if (ans.back() == '0') {
                ans += '1';

            } else {
                ans += '0';
            }

        } else {
            ans += ans.back();
        }
        cout << ans << endl;
    }
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
