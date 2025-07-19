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
    int n, k;
    cin >> n >> k;

    map<int, int>mp;

    V<int>w (n);

    for (auto& x : w)cin >> x, mp[x]++;

    sort (ALL (w));
    w.erase (unique (ALL (w)), w.end ());

    int ans = 0, lst = -1, cnt = 0, t = 0;

    FOR (i, 0, w.sz - 1) {
        if (lst == -1) {
            lst = w[i];
            t += mp[w[i]];
            cnt++;
        } else {
            if (w[i] == lst + 1) {
                cnt++;
                t += mp[w[i]];
                if (cnt > k) {
                    cnt--;
                    t -= mp[w[i - k]];
                }
                lst = w[i];
            } else {
                cnt = 1;
                t = mp[w[i]];
                lst = w[i];
            }
        }
        ans = max (ans, t);
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