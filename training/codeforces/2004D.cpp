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
    int n, q;
    cin >> n >> q;
    V<string> p = {"", "BG", "BR", "BY", "GR", "GY", "RY"};

    V<string> w(n + 1);
    map<int, set<int>> mp;
    FOR(i, 1, n) {
        cin >> w[i];
        FOR(j, 1, 6) {
            if (w[i] == p[j]) {
                mp[j].insert(i);
                break;
            }
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        auto check = [&](string a, string b) {
            map<char, int> mp2;
            mp2[a[0]]++, mp2[a[1]]++, mp2[b[1]]++, mp2[b[0]]++;
            if (sz(mp2) != 4) {
                return 1;
            }
            return 0;
        };

        if (check(w[l], w[r])) {
            cout << r - l << endl;
            continue;
        }

        int ans = 1e18;

        FOR(k, 1, 6) {
            if (w[l] == p[k] || w[r] == p[k]) continue;
            auto it = mp[k].lower_bound(l);
            if (it != mp[k].end()) {
                if (*it < r) {
                    ans = r - l;
                    break;
                }
                ans = min(ans, (*it - l) + (*it - r));
            }
            if (it != mp[k].begin()) {
                it--;
                ans = min(ans, l - *it + r - *it);
            }
        }
        if (ans == 1e18) ans = -1;
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
