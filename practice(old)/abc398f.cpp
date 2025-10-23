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

    int n = s.sz;

    s = ' ' + s;

    V<int>hl (n + 1, 0), hr (n + 1, 0), p (n + 1, 0);
    int P = 131;
    p[0] = 1;

    FOR (i, 1, n)p[i] = p[i - 1] * P;

    FOR (i, 1, n)hl[i] = hl[i - 1] * P + (s[i] - 'A');
    FOR (i, 1, n)hr[i] = hr[i - 1] * P + (s[n - i + 1] - 'A');

    function<int (int, int)>ql = [&] (int l, int r) {
        return hl[r] - hl[l - 1] * p[r - l + 1];
        };

    function<int (int, int)>qr = [&] (int l, int r) {
        return hr[r] - hr[l - 1] * p[r - l + 1];
        };

    FOR (i, 1, n) {
        if (ql (i, n) == qr (1, n - i + 1)) {
            FOR (j, 1, n)cout << s[j];
            FORD (j, 1, i - 1)cout << s[j];
            RE;
        }
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