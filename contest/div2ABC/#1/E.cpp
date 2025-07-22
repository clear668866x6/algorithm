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

int qmi (int a, int b, int mod = 998244353) {
    int res = 1;
    while (b) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve () {
    int n;
    cin >> n;
    V<int>p (n), q (n);
    for (auto& x : p)cin >> x;
    for (auto& x : q)cin >> x;

    int mx1 = 0, mx2 = 0, idx1 = 0, idx2 = 0;

    FOR (i, 0, n - 1) {
        if (p[i] > mx1) {
            mx1 = p[i];
            idx1 = i;
        }
        if (q[i] > mx2) {
            mx2 = q[i];
            idx2 = i;
        }
        if (p[idx1] > q[idx2] || (p[idx1] == q[idx2] && q[i - idx1] > p[i - idx2])) {
            cout << (qmi (2, p[idx1]) + qmi (2, q[i - idx1])) % 998244353 << " ";
        } else {
            cout << (qmi (2, p[i - idx2]) + qmi (2, q[idx2])) % 998244353 << " ";
        }
    }
    cout << endl;
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}