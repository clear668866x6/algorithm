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

    for (int i = 1; i <= n; i++) sa[i] = sa[i - 1] + (s[i] == 'A');
    for (int i = 1; i <= n; i++) sb[i] = sb[i - 1] + (s[i] == 'B');
    for (int i = 1; i <= n; i++) sc[i] = sc[i - 1] + (s[i] == 'C');

    i64 ans = 0;
    map<int, int> mp, mp2, mp3;
    map<array<int, 2>, int> mp4;
    mp[0] = mp2[0] = mp3[0] = 1;
    mp4[{0, 0}] = 1;
    for (int i = 1; i <= n; i++) {
        int s1 = sa[i] - sb[i];
        int s2 = sa[i] - sc[i];
        int s3 = sb[i] - sc[i];

        ans += mp[s1]++;
        ans += mp2[s2]++;
        ans += mp3[s3]++;
        ans -= 2 * mp4[{s1, s3}]++;
    }

    cout << ((i64)n * (n + 1) / 2 - ans);
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