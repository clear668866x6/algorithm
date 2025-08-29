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

    priority_queue<int> q1, q2;

    FOR(i, 1, n) q1.push(0), q2.push(0);

    FOR(i, 1, n) {
        int x;
        cin >> x;
        if (x & 1) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    int a = 0, b = 0;

    FOR(i, 1, n) {
        if (i & 1) {
            int t1 = q1.top(), t2 = q2.top();
            if (t1 > t2) {
                q1.pop();
            } else {
                a += t2;
                q2.pop();
            }
        } else {

            int t1 = q1.top(), t2 = q2.top();
            if (t2 > t1) {
                q2.pop();
            } else {
                b += t1;
                q1.pop();
            }
        }
    }
    if (a > b) {
        cout << "Alice" << endl;
    } else if (a == b) {
        cout << "Tie" << endl;
    } else {
        cout << "Bob" << endl;
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
