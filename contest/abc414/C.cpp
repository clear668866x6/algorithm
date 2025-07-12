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
    int a, n;
    cin >> a >> n;
    int N = n;
    int len = (to_string (n).sz + 1) / 2;
    int t = 1, l = len - 1;
    while (l--)t *= 10;
    n /= t;

    function<int (int)>check = [&] (int x) {
        string p;
        while (x) {
            p += ('0' + x % a);
            x /= a;
        }
        for (int i = 0, j = p.sz - 1;i < j;i++, j--) {
            if (p[i] != p[j]) {
                return 0;
            }
        }
        return 1;
        };


    int ans = 0;

    FOR (i, 1, n) {
        string p = to_string (i);
        string q = p;
        reverse (ALL (p));
        for (auto x : p) {
            q += x;
        }

        int t = 0;


        for (auto x : q) {
            t = t * 10 + (x - '0');
        }

        if (t > N)break;

        if (check (t) && t <= N) {
            ans += t;
        }
    }

    FOR (i, 1, n) {
        string p = to_string (i);
        string q = p;
        p.pop_back ();
        reverse (ALL (p));
        for (auto x : p) {
            q += x;
        }

        int t = 0;

        for (auto x : q) {
            t = t * 10 + (x - '0');
        }

        if (t > N)break;
        if (check (t) && t <= N) {
            ans += t;
        }
    }

    cout << ans;

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