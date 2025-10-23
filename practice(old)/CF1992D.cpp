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

void solve () {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;

    s = 'L' + s;

    int st = 0;
    s += 'L';

    while (1) {
        if (st > n) {
            YES;
            RE;
        }
        if (s[st] == 'L') {
            bool f = false;
            FORD (i, st + 1, min (st + m, n + 1)) {
                if (s[i] == 'L') {
                    st = i;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                FORD (i, st + 1, min (st + m, n + 1)) {
                    if (s[i] != 'C') {
                        st = i;
                        f = 1;
                        break;
                    }
                }
                if (!f) {
                    NO;
                    RE;
                }
            }
        } else if (s[st] == 'W') {
            FOR (i, st, n + 1) {
                if (s[i] == 'C') {
                    NO;
                    RE;
                } else if (s[i] == 'W') {
                    if (!k) {
                        NO;
                        RE;
                    }
                    k--;
                } else {
                    st = i;
                    break;
                }
            }
        }
    }
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