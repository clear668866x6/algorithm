#include <bits/stdc++.h>
#include <cctype>
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
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0, d = 0;

    for (auto x : s) {
        if (islower(x))
            a++;
        else if (isupper(x))
            b++;
        else if (isdigit(x))
            c++;
        else
            d++;
    }

    int ans = 0;

    if (a == 1)
        ans += 25;
    else
        ans += 65 * a;
    if (b == 1)
        ans += 25;
    else
        ans += 65 * b;

    if (c == 1)
        ans += 9;
    else
        ans += 65 * c;

    if (d == 1)
        ans += 3;
    else
        ans += 65 * d;

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
