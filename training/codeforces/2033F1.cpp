#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int j = 1; j <= 100000; j++) {
        int t1 = 1, t2 = 1;
        for (int i = 3; i <= 1000; i++) {
            int tmp = t1 + t2;
            t1 = t2;
            t2 = tmp;
            t1 %= j, t2 %= j;
            if (t2 % j == 0) {
                // cout << "beishu= " << j << ' ' << i << endl;
                cnt++;
                break;
            }
        }
    }

    // int t1 = 1, t2 = 1;
    // for (int i = 3; i <= 100000000; i++) {
    //     int tmp = t1 + t2;
    //     t1 = t2;
    //     t2 = tmp;
    //     if(t2)
    // }
    // cout << t2 << endl;

    cout << cnt << endl;
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