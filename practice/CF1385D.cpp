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
    string s;
    cin >> n >> s;
    s = ' ' + s;

    function<int(int, int, char)> dfs = [&](int l, int r, char c) {
        if (l == r) return int(s[l] != c);
        int tot1 = 0, tot2 = 0;
        int mid = (l + r) >> 1;
        FOR(i, l, mid) tot1 += (s[i] != c);
        FOR(i, mid + 1, r) tot2 += (s[i] != c);
        tot1 += dfs(mid + 1, r, c + 1);
        tot2 += dfs(l, mid, c + 1);
        return min(tot1, tot2);
    };

    cout << dfs(1, n, 'a') << endl;
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
