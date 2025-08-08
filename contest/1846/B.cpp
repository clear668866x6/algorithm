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

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int n = 3;

    V<V<char>> s(n + 1, V<char>(n + 1, 0));

    function<int(char)> check = [&](char x) {
        if (s[1][1] == x && s[1][2] == x && s[1][3] == x ||
            (s[1][1] == x && s[2][1] == x && s[3][1] == x) ||
            (s[1][1] == x && s[2][2] == x && s[3][3] == x) ||
            (s[1][3] == x && s[2][2] == x && s[3][1] == x) ||
            (s[2][1] == x && s[2][2] == x && s[2][3] == x) ||
            (s[3][1] == x && s[3][2] == x && s[3][3] == x) ||
            (s[1][2] == x && s[2][2] == x && s[3][2] == x) ||
            (s[1][3] == x && s[2][3] == x && s[3][3] == x))
            return 1;
        return 0;
    };

    FOR(i, 1, n) {
        FOR(j, 1, n) { cin >> s[i][j]; }
    }

    if (check('O')) {
        cout << "O" << endl;
        RE;
    }

    if (check('+')) {
        cout << "+" << endl;
        RE;
    }
    if (check('X')) {
        cout << "X" << endl;
        RE;
    }

    cout << "DRAW" << endl;
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
