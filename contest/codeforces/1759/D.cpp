#include <bits/stdc++.h>
#include <functional>
#include <string>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
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
    int n, m;
    cin >> n >> m;

    int ans = 0;

    function<int(int, int)> qmi = [&](int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    };

    function<int(int, int)> maxx = [&](int a, int b) {
        string s1 = to_string(a), s2 = to_string(b);
        int cnt1 = 0, cnt2 = 0;
        FORD(i, 0, sz(s1) - 1) {
            if (s1[i] == '0') {
                cnt1++;
            } else
                break;
        }

        FORD(i, 0, sz(s2) - 1) {
            if (s2[i] == '0')
                cnt2++;
            else
                break;
        }

        if (cnt1 > cnt2)
            return a;
        if (cnt1 < cnt2)
            return b;
        return max<int>(a, b);
    };

    FOR(i, 0, 60) {
        FOR(j, 0, 30) {
            int t = qmi(2, i) * qmi(5, j);
            if (t > m)
                break;
            t = m / t * t;
            // cout << t << endl;
            ans = maxx(ans, t * n);
        }
    }

    if (!ans) {
        cout << n * m << endl;
    } else {
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
