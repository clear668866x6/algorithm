#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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

int max(string a, string b) {
    if (sz(a) != sz(b)) return sz(a) > sz(b);
    return a > b;
}

void solve() {
    string a, b;
    cin >> a >> b;
    reverse(ALL(a));
    while (sz(a) > 1 && a.back() == '0') a.pop_back();

    reverse(ALL(b));
    while (sz(b) > 1 && b.back() == '0') b.pop_back();


    reverse(ALL(a));
    reverse(ALL(b));

    if (max(a, b) == 1) {
        cout << ">";
    } else if (a == b) {
        cout << "=";
    } else {
        cout << "<";
    }
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
