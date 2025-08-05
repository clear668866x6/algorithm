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
    int n;
    cin >> n;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    map<int, int> mp;

    FOR(k, 1, n) {
        int ans = w[k];
        FOR(i, 2, ans / i) {
            if (ans % i == 0) {
                int c = 0;
                while (ans % i == 0)
                    ans /= i, c++;
                mp[i] += c;
            }
        }
        if (ans > 1)
            mp[ans] += 1;
    }

    int cnt = 1, tot = mp.sz;

    while (1) {
        int t = 1;
        bool l = false;
        for (auto [a, b] : mp) {
            t *= (b + 1);
            if (t - 1 >= 2 * tot) {
                l = 1;
                break;
            }
        }
        if (!l) {
            cnt--;
            break;
        }
        bool ff = false;
        for (auto& [x, y] : mp) {
            if (y == 2) {
                y -= 2;
                tot--;
                ff = 1;
                break;
            } else if (y > 2) {
                y -= 2;
                ff = 1;
                break;
            }
        }
        if (!ff || tot == 0) {
            if (tot <= 3)
                break;
            tot -= 3;
            for (auto& [x, y] : mp) {
                if (y == 1) {
                    y = 0;
                    break;
                }
            }
            for (auto& [x, y] : mp) {
                if (y == 1) {
                    y = 0;
                    break;
                }
            }
            for (auto& [x, y] : mp) {
                if (y == 1) {
                    y = 0;
                    break;
                }
            }
        }
        cnt++;
    }

    cout << cnt << endl;
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