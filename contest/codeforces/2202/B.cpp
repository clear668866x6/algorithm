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

    int ca = 0, cb = 0;
    for (auto x : s) {
        if (x == 'a') {
            ca++;
        } else if (x == 'b') {
            cb++;
        }
    }

    int st = 0;

    if (n & 1) {
        if (ca > n / 2 + 1 || cb > n / 2) {
            NO;
            RE;
        }
        if (s[0] == 'b') {
            NO;
            RE;
        }
        st = 1;
    } else {
        if (ca > n / 2 || cb > n / 2) {
            NO;
            RE;
        }
        if (s[0] != '?' && s[0] == s[1]) {
            NO;
            RE;
        }
    }
    int t1 = 0, t2 = 0;

    FOR(i, 0, n - 1) {
        if (s[i] == 'a') {
            t1++;
        } else {
            if (t1 > 2) {
                NO;
                RE;
            }
            t1 = 0;
        }

        if (s[i] == 'b') {
            t2++;
        } else {
            if (t2 > 2) {
                NO;
                RE;
            }
            t2 = 0;
        }
    }

    FOR2(i, st, n - 2, 2) {
        if (s[i] != '?' && s[i + 1] == s[i]) {
            NO;
            RE;
        }
    }

    YES;
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
