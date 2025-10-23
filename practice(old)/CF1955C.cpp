#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve() {
  int n, k;
  cin >> n >> k;

  V<int> w(n);
  for (auto &x : w)
    cin >> x;

  V<int> pre(n + 1, 0), suf(n + 2, 0);

  FOR(i, 1, n) pre[i] = pre[i - 1] + w[i - 1];
  FORD(i, 1, n) suf[i] = suf[i + 1] + w[i - 1];

  int t1 =
      (upper_bound(pre.begin() + 1, pre.end(), (k + 1) / 2) - pre.begin() - 1);
  int t2 = (upper_bound(suf.begin(), suf.end(), k / 2, greater<int>()) -
            suf.begin() - 1);

  if (pre[n] <= k) {
    cout << n << endl;
    RE;
  }

  if (t1 >= t2) {
    if (t1 > n || t2 <= 0 || pre[t1] + suf[t2] >= k) {
      cout << n << endl;
    } else {
      cout << n - 1 << endl;
    }
  } else {
    if (pre[t1] > (k + 1) / 2)
      t1--;
    if (suf[t2] > k / 2)
      t2++;
    cout << (t1 + (n + 1 - t2)) << endl;
  }
}

signed main() {
  int Task = 1;

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> Task;

  while (Task--) {
    solve();
  }

  return 0;
}
