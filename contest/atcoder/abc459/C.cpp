#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct BIT {
    static constexpr int N = 6e5 + 10;

    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += i & -i) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= i & -i) ans += tr[i];
        return ans;
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> val(n + 1, 0);

    int tot = 0;
    multiset<int> s;
    for (int i = 1; i <= n; i++) s.insert(0);

    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            s.erase(s.find(val[x]));
            A.add(1, -1);
            A.add(val[x] + 1, 1);
            val[x]++;
            s.insert(val[x]);
            A.add(1, 1);
            A.add(val[x] + 1, -1);
        } else {
            cout << A.query(x + *s.begin()) << '\n';
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