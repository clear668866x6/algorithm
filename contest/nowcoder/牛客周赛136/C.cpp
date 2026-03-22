#include <bits/stdc++.h>
#include <locale>
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

constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ji = (n + 1) / 2, ou = n - ji, c1 = 0, c2 = 0, c3 = 0;

    for (auto x : s) {
        if (x == '?')
            c1++;
        else if (x == 'j')
            c2++;
        else
            c3++;
    }

    int ans = 1;

    while (c2--) {
        ans = ans * ji;
        ji--;
        ans %= mod;
    }

    while (c3--) {
        ans = ans * ou;
        ou--;
        ans %= mod;
    }

    FOR(i, 1, c1) {
        ans = ans * i % mod;
    }
    cout << ans;
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