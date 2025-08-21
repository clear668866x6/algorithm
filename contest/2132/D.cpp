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
    int k;
    cin >> k;

    int l = 0, r = 1e18;

    function<int(int)> check = [&](int x) {
        int t = 1, tot = 0, c = 1;
        while (t * 10 <= x) {
            tot += 9 * t * c;
            t *= 10;
            c++;
        }

        tot += (x - t + 1) * c;
        return tot;
    };

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid) >= k)
            r = mid;
        else
            l = mid;
    }

    int d = k - check(r - 1);
    string s = to_string(r);
    int ans = 0;
    FOR(i, 0, d - 1) {
        ans += (s[i] - '0');
    }

    function<int(int)> calc = [&](int x) {
        int s = 0;
        int t = 1;
        while (t <= x) {
            int tt = t * 10;
            int a = x / tt, b = x % tt;
            FOR(d, 1, 9) {
                int cnt = a * t;
                if (b >= d * t) {
                    if (b >= (d + 1) * t) {
                        cnt += t;
                    } else {
                        cnt += (b - d * t + 1);
                    }
                }
                s += d * cnt;
            }
            t = tt;
        }
        return s;
    };

    ans += calc(l);
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
