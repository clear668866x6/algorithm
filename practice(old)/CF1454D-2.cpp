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
//这个题可以用来做构造保证a_i%i==0且每个数>1
void solve() {
    int n;
    cin >> n;

    int tt = 1, cnt = 1;
    V<int>ans;
    while (1){

        if (!ans.sz){
            ans.pb(2);
            if (n % (tt * 2) || (n / (tt * 2)) % (cnt + 1) || (n / (tt * 2)) <= 1){
                ans[ans.sz - 1] = n / tt;
                break;
            }
            tt *= 2;
        } else{
            ans.pb(cnt);
            cout << (n / (tt * cnt)) % (cnt + 1) << endl;
            cout << tt << ' ' << cnt << endl;
            if (n % (tt * cnt) || (n / (tt * cnt)) % (cnt + 1) || (n / (tt * cnt)) <= 1){
                ans[ans.sz - 1] = n / tt;
                break;
            }
            tt *= cnt;
        }
        cnt++;
    }
    cout << ans.sz << endl;
    for (auto x : ans)cout << x << ' ';
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