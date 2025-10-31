#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int long long
using LL = long long;
const int sqn = 300;
struct Q {
    int l, r, id;
    bool operator<(const Q &x) const {
        if (l / sqn != x.l / sqn) return l < x.l;
        return (l / sqn) & 1 ? r < x.r : x.r < r;
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j * j <= x; j++)
            if (x % j == 0) {
                a[i]++;
                if (x / j != j) a[i]++;
            }
    }
    vector<Q> b(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> b[i].l >> b[i].r;
        b[i].id = i;
    }
    sort(b.begin() + 1, b.end());
    int l = 1, r = 0;
    vector<int> cnt(n + 1), ans(q + 1);
    int tot = 0;
    auto add = [&](int x) -> void {
        tot -= (cnt[x] - 1) * cnt[x] / 2;
        cnt[x]++;
        tot += (cnt[x] - 1) * cnt[x] / 2;
    };
    auto del = [&](int x) -> void {
        tot -= (cnt[x] - 1) * cnt[x] / 2;
        cnt[x]--;
        tot += (cnt[x] - 1) * cnt[x] / 2;
    };
    for (int i = 1; i <= q; i++) {
        int L, R, id;
        L = b[i].l, R = b[i].r, id = b[i].id;
        while (l > L) add(a[--l]);
        while (r < R) add(a[++r]);
        while (l < L) del(a[l++]);
        while (r > R) del(a[r--]);
        ans[id] = tot;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << el;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}