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

    string s1 = "greet", s2 = "invite";
    map<int, vector<string>> mp, mp2;

    for (int i = 0; i < 5; i++) {
        string p;
        p += s1[i];
        mp[1].push_back(p);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            string p;
            p += s1[i];
            p += s1[j];
            mp[2].push_back(p);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                string p;
                p += s1[i];
                p += s1[j];
                p += s1[k];
                mp[3].push_back(p);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                for (int t = k + 1; t < 5; t++) {
                    string p;
                    p += s1[i];
                    p += s1[j];
                    p += s1[k];
                    p += s1[t];
                    mp[4].push_back(p);
                }
            }
        }
    }
    mp[5].push_back(s1);

    for (int i = 0; i < 6; i++) {
        string p;
        p += s2[i];
        mp2[1].push_back(p);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            string p;
            p += s2[i];
            p += s2[j];
            mp2[2].push_back(p);
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                string p;
                p += s2[i];
                p += s2[j];
                p += s2[k];
                mp2[3].push_back(p);
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                for (int t = k + 1; t < 6; t++) {
                    string p;
                    p += s2[i];
                    p += s2[j];
                    p += s2[k];
                    p += s2[t];
                    mp2[4].push_back(p);
                }
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                for (int t = k + 1; t < 6; t++) {
                    for (int t2 = t + 1; t2 < 6; t2++) {
                        string p;
                        p += s2[i];
                        p += s2[j];
                        p += s2[k];
                        p += s2[t];
                        p += s2[t2];
                        mp2[5].push_back(p);
                    }
                }
            }
        }
    }

    mp2[6].push_back(s2);

    int ans = 11;

    vector<vector<int>> pre(n + 1, vector<int>(7, 1e9)), suf(n + 2, vector<int>(7, 1e9));

    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= 6; x++) {
            int l = i, r = i + x - 1;
            if (r > n) break;
            bool f = false;
            string p;
            for (int j = l; j <= r; j++) {
                p += s[j];
            }
            for (auto v : mp2[x]) {
                if (p == v) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                pre[r][x] = min(pre[r - 1][x], 6 - x);
            } else {
                pre[r][x] = min(pre[r - 1][x], pre[r][x]);
            }
        }
        pre[i][0] = min(pre[i - 1][0], 6);
    }

    for (int i = n; i >= 1; i--) {
        for (int x = 1; x <= 6; x++) {
            int l = i - x + 1, r = i;
            if (l < 1) break;
            bool f = false;
            string p;
            for (int j = l; j <= r; j++) {
                p += s[j];
            }
            for (auto v : mp2[x]) {
                if (p == v) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                suf[r][x] = min(suf[r + 1][x], 6 - x);
            } else {
                suf[r][x] = min(suf[r + 1][x], suf[r][x]);
            }
        }
        suf[i][0] = min(suf[i + 1][0], 6);
    }

    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= 5; x++) {
            int l = i, r = i + x - 1;
            if (r > n) break;
            bool f = false;
            string p;
            for (int j = l; j <= r; j++) {
                p += s[j];
            }
            for (auto v : mp[x]) {
                if (p == v) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                int mn = 1e9;
                for (int y = 0; y <= 6; y++) {
                    mn = min(mn, pre[i - 1][y]);
                    mn = min(mn, suf[r + 1][y]);
                }
                ans = min(ans, 5 - x + mn);
            } else {
                int mn = 1e9;
                for (int y = 0; y <= 6; y++) {
                    mn = min(mn, pre[i - 1][y]);
                    mn = min(mn, suf[r + 1][y]);
                }
                ans = min(ans, 5 + mn);
            }
        }
    }

    for (int y = 0; y <= 6; y++) ans = min(ans, 5 + pre[n][y]);

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