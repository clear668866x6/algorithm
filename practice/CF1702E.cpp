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
    V<int> p(n + 1, 0), siz(n + 1, 1);
    iota(ALL(p), 0ll);
    map<int, int> mp;

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    bool f = false;

    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;
        mp[a]++, mp[b]++;
        if (a == b) {
            f = 1;
            continue;
        }
        a = find(a), b = find(b);
        if (a > b) swap(a, b);
        if (a != b) {
            p[a] = b;
            siz[b] += siz[a];
        }
    }

    FOR(i, 1, n) {
        if (mp[i] != 2) {
            NO;
            RE;
        }
    }

    if (f) {
        NO;
        RE;
    }

    FOR(i, 1, n) {
        if (i == p[i] && (siz[i] & 1)) {
            NO;
            RE;
        }
    }
    YES;
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
