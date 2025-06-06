#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
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
    int n, m, k;
    cin >> n >> m >> k;

    V<int>w(n);
    for (auto& x : w)cin >> x;

    priority_queue<int>q1;
    priority_queue<int, V<int>, greater<int>>q2;

    for (auto x : w)q1.push(x);

    function<void(void)> evel = [&]() ->void {
        while (q1.sz > k) {
            q2.push(q1.top());
            q1.pop();
        }
        };


    while (m--) {
        int op, x;
        cin >> op;
        evel();
        if (op == 1) {
            cin >> x;
            q1.push(x);
        } else {
            if (q1.sz != k && !q2.sz) {
                cout << -1 << endl;
            } else {
                cout << q1.top() << endl;
            }
        }
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