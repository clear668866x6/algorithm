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
    int n, d;
    cin >> n >> d;

    V<int> x(n + 1, 0);

    FOR(i, 1, n) {
        cin >> x[i];
    }

    V<int> del;

    FOR(i, 1, n) {
        del.eb(x[i] - x[i - 1] - 1);
    }

    sort(ALL(del));

    map<int, int> mp;

    for (auto x : del) mp[x]++;

    if (mp[del[0]] > 2) {
        cout << del[0] << endl;
    } else {
        auto calc = [&](V<int> x, V<int> del, int p, int n) {
            FOR(i, 1, n) {
                if (x[i] - x[i - 1] - 1 == del[0]) {
                    x.erase(x.begin() + i + p);
                    break;
                }
            }

            sort(ALL(x));
            n--;
            del.clear();

            FOR(i, 1, n) {
                del.eb(x[i] - x[i - 1] - 1);
            }
            sort(ALL(del));

            int l = 0, r = del[0] + 1;

            function<int(int)> check = [&](int val) {
                FOR(i, 1, n) {
                    if ((x[i] - x[i - 1] - 2) / 2 >= val) return 1;
                }
                if (d - x[n] - 1 >= val) return 1;
                return 0;
            };

            while (l + 1 != r) {
                int mid = (l + r) >> 1;
                if (check(mid))
                    l = mid;
                else
                    r = mid;
            }

            return l;
        };

        int ans = max(calc(x, del, 0, n), calc(x, del, -1, n));

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
