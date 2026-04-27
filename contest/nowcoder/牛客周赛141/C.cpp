#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    int l = 1, r = n;

    while (l < r) {
        if (s[l] == s[r])
            l++, r--;
        else if (s[l] == 'm') {
            if (s[r] == s[r - 1] && s[r] == 'n') {
                r -= 2;
                l++;
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            if (s[l] == s[l + 1] && s[l] == 'n') {
                l += 2;
                r--;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}