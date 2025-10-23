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
    string s;
    cin >> s;
    V<int>p (s.sz);

    FOR (i, 0, p.sz - 1)p[i] = i + 1;

    do {
        bool f = false;
        FOR (i, 0, s.sz - 1) {
            if (s[i] == 'p') {
                V<int>w;
                FOR (j, 0, i) {
                    w.eb (p[j]);
                }
                sort (ALL (w));
                FOR (j, 0, w.sz - 1) {
                    if (w[j] != j + 1) {
                        f = 1;
                        break;
                    }
                }
                if (f)break;
            } else if (s[i] == 's') {
                V<int>w;
                FOR (j, i, s.sz - 1) {
                    w.eb (p[j]);
                }
                sort (ALL (w));
                FOR (j, 0, w.sz - 1) {
                    if (w[j] != j + 1) {
                        f = 1;
                        break;
                    }
                }
                if (f)break;
            }
        }
        if (!f) {
            for (auto x : p)cout << x << ' ';
            cout << endl;
        }
    } while (next_permutation (ALL (p)));
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}