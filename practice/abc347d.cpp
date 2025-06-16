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
    int a, b, c;
    cin >> a >> b >> c;

    int d = c;
    int cnt = 0, c1 = 0;
    string s;

    while (c) {
        if (c & 1) c1++;
        s += '0' + (c & 1);
        cnt++;
        c /= 2;
    }

    reverse (ALL (s));

    string ans1, ans2;

    int del = 0;
    FOR (i, 0, cnt - 1) {
        del = abs (a - b);
        if (s[i] == '1') {
            if (del) {
                ans1 += a > b ? '1' : '0';
                ans2 += a > b ? '0' : '1';
                a > b ? a-- : b--;
                del--;
            } else {
                ans1 += a ? '1' : '0', ans2 += a ? '0' : '1';
                a ? a-- : b--;
            }
            c1--;
        } else {
            if (a >= c1 && b >= c1) {
                ans1 += '1', ans2 += '1';
                a--, b--;
            } else {
                ans1 += '0', ans2 += '0';
            }
        }
    }
    reverse (ALL (ans1)), reverse (ALL (ans2));
    while (a < 0 && b < 0) {
        FOR (i, 0, ans1.sz - 1) {
            if (ans1[i] == ans2[i] && ans1[i] == '1') {
                ans1[i] = ans2[i] = '0';
                a++, b++;
                break;
            }
        }
    }
    while (a && b) {
        a--, b--;
        ans1 += '1', ans2 += '1';
    }
    reverse (ALL (ans1)), reverse (ALL (ans2));
    if (a || b) {
        cout << -1 << endl;
    } else {
        int a1 = 0, a2 = 0;
        for (auto x : ans1)a1 = a1 * 2 + (x - '0');
        for (auto x : ans2)a2 = a2 * 2 + (x - '0');
        if (ans1.sz > 60 || ans2.sz > 60) {
            cout << -1 << endl;
            RE;
        }
        cout << a1 << ' ' << a2;
    }
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