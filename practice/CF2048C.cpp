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
//卡在：没有进一步发现性质：长度是恒定的。

void solve () {
    string s;
    cin >> s;

    int n = s.sz;

    int len = -1;

    FOR (i, 0, n - 1) {
        if (s[i] == '0') {
            len = i;
            break;
        }
    }

    string ans = "", t1 = s, t2 = "";
    int ansl = 0, ansr = 0;

    if (len == -1) {
        cout << "1 1 1 " << n << endl;
        RE;
    }
    len = n - len;

    for (int l = 1;l + len - 1 <= n;l++) {
        int r = l + len - 1;
        string p = t1, q;
        if (s[l - 1] == '0')continue;
        FOR (i, l - 1, r - 1) {
            q += s[i];
        }
        FOR (i, 0, len - 1) {
            if (s[n - len + i] == q[i]) {
                p[i] = '0';
            } else {
                p[i] = '1';
            }
        }
        if (p > ans) {
            ans = p;
            ansl = l, ansr = r;
        }
    }

    cout << ansl << ' ' << ansr << ' ' << "1 " << n << endl;
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