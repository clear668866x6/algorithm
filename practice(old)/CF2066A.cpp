#include <bits/stdc++.h>
using namespace std;

#define int int64_t
// #define endl "\n"

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
// 题目看错了我靠，题目说的是顶点而不是下标。
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    V<int> w(n);

    FOR(i, 0, n - 1) cin >> w[i], mp[w[i]] = i + 1;

    bool f = false;

    FOR(i, 1, n) {
        if (!mp[i]) {
            cout << "? " << i << ' ' << (1 + (i == 1)) << endl;
            int t1;
            cin >> t1;
            if (t1) {
                cout << "! B" << endl;
            } else {
                cout << "! A" << endl;
            }
            RE;
        }
    }

    int idxmn = 0, idxmx = 0;

    FOR(i, 0, n - 1) {
        if (w[i] == 1)
            idxmn = i + 1;
        if (w[i] == n)
            idxmx = i + 1;
    }

    cout << "? " << idxmn << ' ' << idxmx << endl;
    int t1, t2;
    cin >> t1;
    cout << "? " << idxmx << " " << idxmn << endl;
    cin >> t2;
    if (t1 >= (n - 1) && t1 == t2) {
        cout << "! B" << endl;
    } else {
        cout << "! A" << endl;
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
