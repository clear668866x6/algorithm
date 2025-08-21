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
    int n;
    cin >> n;

    int t = n;

    int ans = 0;

    function<int(int, int)> qmi = [&](int a, int b) {
        if (b < 0) return (int)0;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    };

    string s;

    while (t) {
        s += ('0' + t % 3);
        t /= 3;
    }

    FOR(i, 0, sz(s) - 1) {
        if (s[i] == '1') {
            ans += (qmi(3, i + 1) + i * qmi(3, i - 1));
        } else if (s[i] == '2') {
            ans += (qmi(3, i + 1) + i * qmi(3, i - 1)) * 2;
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
