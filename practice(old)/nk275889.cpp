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
//验证check无非就两种：基准值、是否满足题目的某种特性

void solve () {
    int n;
    cin >> n;
    V<int>w (n);
    for (auto& x : w)cin >> x;

    int l = 0, r = 1e7;

    function<bool (int)>check = [&] (int x){
        map<int, int>mp;

        for (auto t : w){
            while (t > x)t /= 2;
            mp[t]++;
        }

        int mex = x;
        while (mex >= 0 && mp[mex]){
            mp[mex / 2] += mp[mex] - 1;
            mex--;
            if (mex <= -1){
                return true;
            }
        }
        return mex <= -1;

        };

    while (l + 1 != r){
        int mid = l + r >> 1;
        if (check (mid))l = mid;
        else r = mid;
    }
    cout << r << endl;
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