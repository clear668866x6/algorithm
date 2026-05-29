#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;

    map<char, int> mp, mp2, mp3;

    for (auto x : s) {
        if (x >= 'A' && x <= 'Z' || (x >= 'a' && x <= 'z'))
            mp[x]++;
        else if (x >= '0' && x <= '9')
            mp2[x]++;
        else if (x == '*' || x == '#')
            mp3[x]++;
    }

    if (!mp.empty() && !mp2.empty() && !mp3.empty()) {
        bool f = false;
        for (auto x : s) {
            if (mp[x] > 2 || mp2[x] > 2 || mp3[x] > 2) {
                f = 1;
                break;
            }
        }
        if (!f) {
            cout << "2\n";
        } else {
            cout << "1\n";
        }
    } else {
        cout << "0\n";
    }
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