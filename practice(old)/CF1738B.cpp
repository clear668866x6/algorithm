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
    V<int>s(k);

    for (auto& x : s)cin >> x;

    V<int>p;

    if (k == 1){
        Yes;
        RE;
    }

    FOR(i, 1, k - 1){
        p.eb(s[i] - s[i - 1]);
    }

    FOR(i, 1, p.sz - 1){
        if (p[i - 1] > p[i]){
            No;
            RE;
        }
    }

    if (s[0] >= 0){
        FOR(i, 1, k - 1){
            if (s[i] < s[i - 1]){
                No;
                RE;
            }
        }
    }

    if (s[0] > (n - k + 1) * (s[1] - s[0])){
        No;
        RE;
    }
    Yes;

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