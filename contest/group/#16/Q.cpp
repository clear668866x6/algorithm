#include <bits/stdc++.h>
#include <numeric>
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

    V<int> w(n + 1, 0);

    map<int, int> mp, mp2;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;

    int t = accumulate(ALL(w), 0ll);

    if (t & 1) {
        NO;
        RE;
    }

    int s = 0;

    FOR(i, 1, n) {
        s += w[i];
        mp[w[i]]--, mp2[w[i]]++;
        if (s == t / 2) {
            YES;
            RE;
        }
        if (s < t / 2) {
            if (mp[t / 2 - s]) {
                YES;
                RE;
            }
        }
        if (s > t / 2) {
            if (mp2[s - t / 2]) {
                YES;
                RE;
            }
        }
    }
    NO;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}