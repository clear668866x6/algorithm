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

int mod = 1e9 + 7;

void solve () {
    string s;
    cin >> s;

    int ans = 1, cnt1 = 0, cnt2 = 0;

    V<int>f (s.sz + 1, 0);

    f[2] = 2, f[3] = 3;
    f[1] = f[0] = 1;

    FOR (i, 4, s.sz){
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    bool fu = 0, fn = 0;

    for (auto x : s){
        if (x == 'u'){
            if (cnt2){
                (ans *= f[cnt2]) %= mod;
                cnt2 = 0;
            }
            cnt1++;
        } else if (x == 'n'){
            if (cnt1){
                (ans *= f[cnt1]) %= mod;
                cnt1 = 0;
            }
            cnt2++;
        } else{
            if (x == 'm' || x == 'w'){
                cout << 0 << endl;
                RE;
            }
            (ans *= f[cnt1]) %= mod;
            (ans *= f[cnt2]) %= mod;

            cnt1 = 0;
            cnt2 = 0;
        }
    }
    if (cnt1){
        (ans *= f[cnt1]) %= mod;
        cnt1 = 0;
    }if (cnt2){
        (ans *= f[cnt2]) %= mod;
        cnt2 = 0;
    }

    cout << ans << endl;

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