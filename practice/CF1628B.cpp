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

    V<string>w (n);
    bool f = false;
    FOR (i, 0, n - 1) {
        cin >> w[i];
        if (w[i].sz == 1)f = 1;
        string a = w[i], b = a;
        reverse (ALL (b));
        if (a == b)f = 1;
    }

    if (f) {
        YES;
        RE;
    }

    map<string, int>mp1, mp2, mp3, mp4;

    FOR (i, 0, n - 1) {
        string s = w[i], t = s;
        if (s.sz == 2) {
            reverse (ALL (t));
            if (mp1[s]) {//2 2
                YES;
                RE;
            }
            mp1[t]++;
            t = s;
            if (mp4[s]) {//3  2
                YES;
                RE;
            }
            reverse (ALL (t));
            mp3[t]++;
        } else {
            reverse (ALL (t));
            if (mp2[s]) {//3  3
                YES;
                RE;
            }
            mp2[t]++;
            t = s;
            reverse (ALL (t));
            t.pop_back ();
            reverse (ALL (t));
            if (mp1[t]) {// 2   3
                YES;
                RE;
            }
            t = s;
            t.pop_back ();
            reverse (ALL (t));
            mp4[t]++;
        }
    }

    NO;

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