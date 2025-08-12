#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    int n, k;
    cin >> n >> k;

    V<int> a(k + 1, 0), b(k + 1, 0);

    FOR(i, 1, k) cin >> a[i];
    FOR(i, 1, k) cin >> b[i];

    FOR(i, 1, k) {
        if (a[i] < b[i]) {
            NO;
            RE;
        }
    }

    FOR(i, 2, k) {
        if ((a[i] < b[i]) || a[i] - a[i - 1] < b[i] - b[i - 1]) {
            NO;
            RE;
        }
    }

    YES;

    string ans;

    int st = 0;

    FOR(i, 1, k) {
        if (i == 1) {
            ans += "ab";
            ans += string(b[i] - 2, 'c');
            int cnt = a[i] - b[i];
            FOR(j, 0, cnt - 1) {
                ans += 'a' + (st % 3);
                st++;
            }
        } else {
            int cnt = a[i] - a[i - 1] - b[i] + b[i - 1];
            FOR(j, 0, cnt - 1) {
                ans += 'a' + (st % 3);
                st++;
            }
            ans += string(b[i] - b[i - 1], char(i + 1 + 'a'));
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