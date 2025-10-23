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

void solve() {
    int n;
    cin >> n;

    V<PII>ans;

    int mx = 0;

    FOR(i, 2, n / i){
        if (n % i == 0){
            int s = 0;
            while (n % i == 0)n /= i, s++;
            ans.pb({ s,i });
            mx = max(mx, s);
        }
    }
    if (n > 1){
        ans.pb({ 1,n });
        mx = max<int>(mx, 1);
    }

    sort(ALL(ans));

    cout << mx << endl;

    // for (auto [x, y] : ans){
    //     cout << x << ' ' << y << endl;
    // }

    int t = 1, cur = mx;

    FORD(i, 0, ans.sz - 1){
        if (ans[i].fi == cur){
            t *= ans[i].se;
        } else{
            int p = cur - ans[i].fi;
            while (p--){
                cout << t << ' ';
            }
            cur = ans[i].fi;
            t *= ans[i].se;
        }
    }

    int p = cur;
    while (p--){
        cout << t << ' ';
    }

    cout << endl;

}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    while (Task--) {
        solve();
    }

    return 0;
}