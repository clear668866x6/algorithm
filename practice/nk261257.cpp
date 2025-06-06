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
//教训：下次想清楚再写

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    V<int>w(n);
    for (auto& x : w)cin >> x;

    V<int>a(m + 1, 0), pre(m + 1, 0);
    for (auto x : w)a[x]++;
    a[0] = 1e18;
    V<int>b = a;
    sort(a.begin() + 1, a.end());
    FOR(i, 1, m)pre[i] = pre[i - 1] + a[i];
    function<bool(int, int)>check = [&](int x, int id){
        int t = upper_bound(a.begin() + 1, a.end(), x) - a.begin() - 1;
        int ans = 0;
        if (a[t] == x){
            ans = pre[m] - pre[t - 1] - (m - t + 1) * x;
        } else{
            ans = pre[m] - pre[t] - (m - t) * x;
        }
        if (b[id] >= x){
            ans -= b[id];
            ans += x;
        }

        return ans <= k;
        };


    FOR(i, 1, m){
        if (n - b[i] < k){
            cout << -1 << ' ';
            continue;
        }
        int l = -1, r = n - b[i] + 1;

        while (l + 1 != r){
            int mid = l + r >> 1;
            if (check(mid, i))r = mid;
            else l = mid;
        }
        cout << r << ' ';
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}