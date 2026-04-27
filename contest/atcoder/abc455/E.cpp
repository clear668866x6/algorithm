#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    vector<int> sa(n + 1, 0), sb(n + 1, 0), sc(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        sa[i] = sa[i - 1] + (s[i] == 'A');
        sb[i] = sb[i - 1] + (s[i] == 'B');
        sc[i] = sc[i - 1] + (s[i] == 'C');
    }

    i64 ans = (i64)n * (n + 1) / 2;
    map<array<int, 2>, int> mp;
    map<int, int> mp2, mp3, mp4;
    mp[{0, 0}] = 1;
    mp2[0] = mp3[0] = mp4[0] = 1;

    for (int i = 1; i <= n; i++) {
        ans -= mp2[sa[i] - sb[i]];
        mp2[sa[i] - sb[i]]++;
        ans -= mp3[sa[i] - sc[i]];
        mp3[sa[i] - sc[i]]++;
        ans -= mp4[sb[i] - sc[i]];
        mp4[sb[i] - sc[i]]++;
        ans += 2 * mp[{sa[i] - sb[i], sb[i] - sc[i]}];
        mp[{sa[i] - sb[i], sb[i] - sc[i]}]++;
    }

    cout << ans;
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