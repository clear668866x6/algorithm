#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct DoubleHeap {
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    void push(int x) {
        if (!q1.empty() && x > q1.top())
            q2.push(x);
        else
            q1.push(x);

        while (abs((int)q1.size() - (int)q2.size()) > 1) {
            if (q1.size() > q2.size()) {
                q2.push(q1.top());
                q1.pop();
            } else {
                q1.push(q2.top());
                q2.pop();
            }
        }
    }

    int get() {
        if (q1.size() > q2.size()) {
            return q1.top();
        }
        return q2.top();
    }

} A;

void solve() {
    int x, q;
    cin >> x >> q;
    A.push(x);

    while (q--) {
        int a, b;
        cin >> a >> b;
        A.push(a), A.push(b);
        cout << A.get() << '\n';
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