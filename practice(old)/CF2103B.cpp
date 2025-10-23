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

    int ans = n + (s[0] == '1');

    FOR (i, 1, n - 1) {
        if (s[i] != s[i - 1])ans++;
    }

    V<int>w;

    FOR (i, 0, n - 1) {
        w.eb (s[i] - '0');
    }

    w.erase (unique (ALL (w)), w.end ());
    map<int, int>mp;
    for (auto x : w)mp[x]++;

    if (s[0] == '1') {
        if (mp[0]) {
            if (mp[1] == 1) {
                ans--;
            } else {
                ans -= 2;
            }
        }
    } else {
        if (mp[0] >= 2 && mp[1] == 1)ans -= 1;
        if (mp[0] >= 2 && mp[1] > 1)ans -= 2;
    }
    cout << ans << endl;

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