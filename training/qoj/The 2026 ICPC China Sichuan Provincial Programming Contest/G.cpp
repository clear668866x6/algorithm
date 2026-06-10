#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector<i64> sum(n + 1, 0), ssum(n + 2, 0);

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + w[i];
    for (int i = n; i >= 1; i--) ssum[i] = ssum[i + 1] + w[i];
    vector<i64> s1(n + 2, 0), s2(n + 2, 0), s3(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        if (i & 1) {
            s1[i] = s1[i + 1] + w[i];
            s2[i] = s2[i + 1];
        } else {
            s1[i] = s1[i + 1];
            s2[i] = s2[i + 1] + w[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            s3[i] = s3[i - 1];
        } else {
            s3[i] = s3[i - 1] + w[i];
        }
    }

    vector<i64> suf1(n + 2, 0), suf2(n + 2, 0), suf3(n + 2, 0), suf4(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        if (i & 1) {
            suf1[i] = ssum[i] - 2 * s1[i];
            suf3[i] = ssum[i] - 2 * s2[i];
        } else {
            suf2[i] = ssum[i] - 2 * s2[i];
            suf4[i] = ssum[i] - 2 * s1[i];
        }
    }

    i64 ans = 0;
    map<i64, int> mp, mp2, mp3, mp4;

    for (int i = n; i >= 0; i--) {
        int j = i + 2;
        if (j <= n + 1) {
            if (j & 1) {
                mp[suf1[j]]++;
                mp3[suf3[j]]++;
            } else {
                mp2[suf2[j]]++;
                mp4[suf4[j]]++;
            }
        }

        i64 del = k - (sum[i] - 2 * s3[i]);
        if (i & 1) {
            ans += mp[del];
            ans += mp2[del];
        } else {
            ans += mp3[del];
            ans += mp4[del];
        }
    }

    cout << ans << '\n';
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