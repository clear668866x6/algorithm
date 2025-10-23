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
#define sz size()//我们将输入的序列分为若干段，每一段都要包含1到k中的数，记录最多可分为的段数,同样+1就可以了。
//[1-k]组成所有一位数，[1-k][1-k]组成所有两位数，最多满足两位，那么答案就是3
void solve () {
    int n, k;
    cin >> n >> k;

    V<int>w (n);
    map<int, int>mp;
    for (auto& x : w)cin >> x, mp[x]++;

    FOR (i, 1, k) {
        if (!mp[i]) {
            cout << 1 << endl;
            RE;
        }
    }

    int cnt = 1, p = 0;

    FOR (i, 1, n - 1) {
        if (w[i] == w[i - 1] && w[i] <= k) {
            cnt++;
        } else {
            if (mp[w[i - 1]] == cnt) {
                p++;
            }
            cnt = 1;
        }
    }

    if (mp[w[n - 1]] == cnt && w[n - 1] <= k)p++;

    if (p >= 2) {
        cout << 2 << endl;
    } else {
        int ans = 0, tot = 0;
        map<int, int>mp;
        FOR (i, 0, n - 1) {
            if (!mp[w[i]]) {
                tot++;
                mp[w[i]] = 1;
            }
            if (tot == k) {
                ans++;
                tot = 0;
                FOR (j, 1, k)mp[j] = 0;
            }
        }

        cout << ans + 1 << endl;
    }
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