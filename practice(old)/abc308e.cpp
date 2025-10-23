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
    int n;
    cin >> n;
    V<int>w (n);
    for (auto& x : w)cin >> x;

    string s;
    cin >> s;

    V<V<int>>pre (n + 2, V<int> (3, 0)), suf (n + 2, V<int> (3, 0));

    FOR (i, 1, n){
        if (s[i - 1] == 'M'){
            pre[i][0] = pre[i - 1][0] + (w[i - 1] == 0);
            pre[i][1] = pre[i - 1][1] + (w[i - 1] == 1);
            pre[i][2] = pre[i - 1][2] + (w[i - 1] == 2);
        } else{
            pre[i][0] = pre[i - 1][0];
            pre[i][1] = pre[i - 1][1];
            pre[i][2] = pre[i - 1][2];
        }
    }

    FORD (i, 1, n){
        if (s[i - 1] == 'X'){
            suf[i][0] = suf[i + 1][0] + (w[i - 1] == 0);
            suf[i][1] = suf[i + 1][1] + (w[i - 1] == 1);
            suf[i][2] = suf[i + 1][2] + (w[i - 1] == 2);
        } else{
            suf[i][0] = suf[i + 1][0];
            suf[i][1] = suf[i + 1][1];
            suf[i][2] = suf[i + 1][2];
        }
    }

    int ans = 0;

    function<int (array<int, 3>)>mex = [&] (array<int, 3>w){
        int mex = 0;
        unordered_set<int>s;
        FOR (i, 0, 2){
            s.insert (w[i]);
            while (s.count (mex))mex++;
        }
        return mex;
        };

    FOR (i, 1, n){
        if (s[i - 1] == 'E'){
            FOR (k1, 0, 2){
                FOR (k2, 0, 2){
                    array<int, 3>t = { w[i - 1],k1,k2 };
                    int me = mex (t);
                    ans += (pre[i - 1][k1] * suf[i + 1][k2]) * me;
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