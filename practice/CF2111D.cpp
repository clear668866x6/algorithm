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
//晦气，做的跟屎一样
void solve () {
    int n, m;
    cin >> n >> m;

    V<int>a (m + 1, 0);

    FOR (i, 1, m)cin >> a[i];

    map<int, V<int>>mp, mp2;
    V<int>t, ans;

    FOR (i, 1, m) {
        mp[a[i] / 100].eb (a[i]);
        t.eb (a[i] / 100);
    }

    sort (ALL (t));
    t.erase (unique (ALL (t)), t.end ());

    int l = 0, r = t.sz - 1;
    int j1 = 0, j2 = 0;
    FOR (i, 0, n - 1) {
        V<int>ans;
        int t1 = l, t2 = r;
        FOR (j, 0, 5) {
            if (j & 1) {
                ans.eb (mp[t[t1]][(j1) % mp[t[t1]].sz]);
                j1++;
            } else {
                ans.eb (mp[t[t2]][(j2) % mp[t[t2]].sz]);
                j2++;
            }
        }
        l++, r--;
        for (auto x : ans)cout << x << ' ';
        cout << endl;
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