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
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    map<char, int>mp;

    for (auto x : s)mp[x]++;

    V<int>vis(n + 2, 0);

    FOR(i, 1, n){
        if (s[i - 1] != c){
            vis[i] = 1;
        }
    }

    if (mp[c] == n){
        cout << 0 << endl;
    } else{

        FOR(i, 2, n){
            int cnt = 0;
            FOR2(j, i, n, i){
                if (vis[j])cnt++;
            }
            if (!cnt){
                cout << 1 << endl;
                cout << i << endl;
                RE;
            }
        }


        cout << 2 << endl;
        cout << n << ' ' << n - 1 << endl;

    }
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