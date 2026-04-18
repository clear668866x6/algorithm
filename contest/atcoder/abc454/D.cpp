#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string a, b;
    cin >> a >> b;

    vector<char> sa, sb;
    int cnt = 0;

    for (int i = 0; i < a.size(); i++) {
        if (sa.empty()) {
            if (a[i] == 'x') {
                cnt++;
            } else {
                cnt = 0;
            }
            sa.push_back(a[i]);
        } else {
            if (a[i] == 'x')
                cnt++, sa.push_back(a[i]);
            else if (a[i] == '(') {
                cnt = 0;
                sa.push_back(a[i]);
            } else {
                if (cnt == 2) {
                    if (sa[sa.size() - 3] == '(') {
                        sa.pop_back();
                        sa.pop_back();
                        sa.pop_back();
                        sa.push_back('x');
                        sa.push_back('x');
                    } else {
                        cnt = 0;
                        sa.push_back(a[i]);
                    }
                } else {
                    cnt = 0;
                    sa.push_back(a[i]);
                }
            }
        }
    }

    cnt = 0;

    for (int i = 0; i < b.size(); i++) {
        if (sb.empty()) {
            if (b[i] == 'x') {
                cnt++;
            } else {
                cnt = 0;
            }
            sb.push_back(b[i]);
        } else {
            if (b[i] == 'x')
                cnt++, sb.push_back(b[i]);
            else if (b[i] == '(') {
                cnt = 0;
                sb.push_back(b[i]);
            } else {
                if (cnt == 2) {
                    if (sb[sb.size() - 3] == '(') {
                        sb.pop_back();
                        sb.pop_back();
                        sb.pop_back();
                        sb.push_back('x');
                        sb.push_back('x');
                    } else {
                        cnt = 0;
                        sb.push_back(b[i]);
                    }
                } else {
                    cnt = 0;
                    sb.push_back(b[i]);
                }
            }
        }
    }

    if (sa == sb) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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