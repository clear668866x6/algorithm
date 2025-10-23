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
    int n, k;
    cin >> n >> k;
    V<int>w(k);
    set<int>s;
    for (auto& x : w)cin >> x, s.insert(x);

    V<int>p(n + 1, 0);

    function<int(int)>find = [&](int x){
        if (x != p[x])p[x] = find(p[x]);
        return p[x];
        };

    FOR(i, 1, n)p[i] = i;

    V<V<int>>g(n + 1);

    FOR(i, 2, n){
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    FOR(i, 1, n){
        if (!s.count(i))continue;
        for (auto& x : g[i]){
            if (s.count(x)){
                int a = find(i), b = find(x);
                if (a != b){
                    p[a] = b;
                }
            }
        }
    }

    int ans = 0;
    set<int>id;

    FOR(i, 1, n){
        if (s.count(i) && find(i) == i){
            ans++;
            id.insert(i);
        }
    }

    int mod = 1e9 + 7;

    V<int>cnt(n + 1, 0);

    FOR(i, 1, n){
        if (s.count(i)){
            int t = 0;
            for (auto& x : g[i]){
                if (!s.count(x)){
                    t++;
                }
            }
            cnt[find(i)] += t;
        }
    }

    int ans2 = 1;

    FOR(i, 1, n){
        if (id.count(i)){
            ans2 = ans2 * cnt[i] % mod;
        }
    }

    cout << ans << ' ' << ans2 << endl;

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