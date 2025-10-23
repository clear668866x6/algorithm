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
    int a, b, L, R;
    cin >> a >> b >> L >> R;
    int delta = b - a;
    int l = -1, r = 1e9;

    function<bool (int)>check1 = [&] (int x) {
        int l = x * L, r = x * R;
        if (delta > r)return false;
        if (delta < l)return true;
        if (delta >= l && delta <= r) {
            return true;
        }
        return false;
        };

    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (check1 (mid))r = mid;
        else l = mid;
    }

    if (r == 1e9 || !(delta >= r * L && delta <= r * R)) {
        cout << -1 << endl;
        RE;
    }

    V<int>ans;

    ans.eb (r);

    l = -1, r = 1e9;

    function<bool (int)>check2 = [&] (int x) {
        int l = x * L, r = x * R;
        if (delta > r)return true;
        if (delta < l)return false;
        if (delta >= l && delta <= r)return true;
        return false;
        };

    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (check2 (mid))l = mid;
        else r = mid;
    }
    if (l == -1 || !(delta >= l * L && delta <= l * R)) {
        cout << -1 << endl;
        RE;
    }
    ans.eb (l);

    cout << ans[0] << ' ' << ans[1] << endl;
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