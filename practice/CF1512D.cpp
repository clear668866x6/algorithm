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
    int m = n + 2;
    V<int>w(m);
    int tot = 0;

    for (auto& x : w)cin >> x, tot += x;
    V<int>b = w;
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    sort(ALL(w));

    tot -= w[m - 1];

    FOR(i, 0, m - 2){
        if (tot - w[i] == w[m - 1]){
            FOR(j, 0, i - 1)cout << w[j] << ' ';
            FOR(j, i + 1, m - 2)cout << w[j] << ' ';
            cout << endl;
            RE;
        }
    }

    int id = 0;

    FOR(i, 0, m - 1){
        if (b[b.sz - 2] == w[i]){
            id = i;
            break;
        }
    }

    tot += w[m - 1];
    tot -= w[id];

    FOR(i, 0, m - 1){
        if (tot - w[i] == w[id] && i != id){
            if (i < id){
                FOR(j, 0, i - 1)cout << w[j] << ' ';
                FOR(j, i + 1, id - 1)cout << w[j] << ' ';
                FOR(j, id + 1, m - 1)cout << w[j] << ' ';
            } else{
                FOR(j, 0, id - 1)cout << w[j] << ' ';
                FOR(j, id + 1, i - 1)cout << w[j] << ' ';
                FOR(j, i + 1, m - 1)cout << w[j] << ' ';
            }
            cout << endl;
            RE;
        }
    }

    cout << -1 << endl;

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