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
    int n;
    string s;
    cin >> n >> s;

    if (s[s.sz - 1] == '1') {
        No;
        RE;
    }

    map<int, int>mp;
    map<int, map<int, int>>vis;

    FOR (i, 0, s.sz - 1) {
        if (s[i] == '0') {
            int t = i + 1, c1 = 0;

            FOR (j, 0, n - 1) {
                if (t >> j & 1) {
                    c1++;
                }
            }

            FOR (j, 0, n - 1) {
                if (t >> j & 1) {
                    vis[c1][j] = 1;
                }
            }
            mp[c1]++;
        }
    }

    bool f = false;

    FOR (i, 0, n - 1) {
        bool ff = false;
        FOR (j, 1, n) {
            if (!vis[j][i]) {
                ff = true;
                break;
            }
        }
        if (!ff) {
            Yes;
            RE;
        }
    }
    No;
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