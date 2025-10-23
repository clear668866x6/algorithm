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
    int n = s.sz, mx = 0;

    map<char, int>mp;

    for (auto x : s)mp[x]++;

    for (auto [x, y] : mp){
        mx = max (mx, y);
    }
    if (mx > n / 2){
        cout << -1 << endl;
        RE;
    }

    V<pair<char, int>>w (ALL (mp));
    string ans;

    FOR (i, 0, n - 1){
        sort (ALL (w), [&] (pair<char, int>a, pair<char, int>b){
            return a.se > b.se;
            });

        bool f = false;
        for (auto& [x, y] : w){
            if (x != s[i] && y){
                ans += x;
                y--;
                f = 1;
                break;
            }
        }

        if (!f){
            FOR (j, 0, ans.sz - 1){
                if (ans[j] != s[i] && s[j] != s[i]){
                    ans += ans[j];
                    ans[j] = s[i];
                    break;
                }
            }
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