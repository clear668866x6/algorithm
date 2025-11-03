#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_backv
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

int Alice(string s) {
    int n = sz(s);
    s = ' ' + s;
    int p = 0;
    FOR(i, 1, n) {
        if (s[i] == '1') p += i;
    }
    return p;
}

int Bob(string s, int X) {
    int n = sz(s);
    s = ' ' + s;
    int c = 0;
    FOR(i, 1, n) {
        if (s[i] == '1') c += i;
    }

    return abs(X - c);
}
