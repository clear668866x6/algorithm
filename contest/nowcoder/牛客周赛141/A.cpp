#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    string s = to_string(n);
    string p = s;
    reverse(s.begin(), s.end());

    if (s != p) {
        cout << "NO";
    } else {
        int t = (int)sqrt(n);
        if (t * t != n) {
            cout << "NO";
        } else {
            s = to_string(t);
            p = s;
            reverse(s.begin(), s.end());
            if (s != p) {
                cout << "NO";
            } else {
                cout << "YES";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}