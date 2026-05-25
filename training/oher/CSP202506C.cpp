#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n = 72;
    int t;
    cin >> t;

    map<i64, vector<string>> sed25;
    map<i64, vector<string>> rev25;
    map<i64, vector<string>> mp25;
    map<i64, vector<string>> mp12;
    map<i64, vector<string>> sed12;
    map<i64, vector<string>> rev12;
    auto getsanlie = [&](i64 x, int n) {
        i128 ans = (u128)x * 47055833459ull;
        ans /= (1ull << (64 - n));
        ans %= (1ull << n);
        return ans;
    };

    for (int K = 1; K <= t; K++) {
        string s;
        cin >> s;
        s = ' ' + s;

        string res1, res2;
        i64 res3 = 0;

        if (s[1] == '1') {
            auto get = [&](int x) {
                if (x == 0)
                    return ' ';
                else if (x >= 1 && x <= 10)
                    return char('0' + x - 1);
                else if (x <= 36)
                    return char('A' + x - 11);
                return '_';
            };

            i64 x1 = 0, x2 = 0;
            for (int i = 2; i <= 59; i++) {
                x1 = x1 * 2 + (s[i] - '0');
            }

            for (int i = 60; i <= n - 1; i++) {
                x2 = x2 * 2 + (s[i] - '0');
            }

            i64 t = 38, tmp = x1;
            string a1;
            for (int i = 1; i <= 11; i++) {
                a1 += get(tmp % 38);
                tmp /= t;
            }
            reverse(a1.begin(), a1.end());
            i64 tmp1 = getsanlie(x1, 12);
            i64 tmp2 = getsanlie(x1, 25);

            if (s.back() == '1') {
                res1 = a1;

                if (mp12[x2].empty()) {
                    res2 = "###";
                } else {
                    res2 = "#";
                    res2 += mp12[x2].back();
                }
                mp12[tmp1].push_back(a1);
                mp25[tmp2].push_back(a1);
            } else {
                if (mp12[x2].empty()) {
                    res1 = "###";
                } else {
                    res1 = "#";
                    res1 += mp12[x2].back();
                }

                res2 = a1;
                mp12[tmp1].push_back(a1);
                mp25[tmp2].push_back(a1);
            }

        } else {
            i64 x1 = 0, x2 = 0, x3 = 0;

            for (int i = 2; i <= 29; i++) {
                x1 = x1 * 2 + (s[i] - '0');
            }

            for (int i = 30; i <= 57; i++) {
                x2 = x2 * 2 + (s[i] - '0');
            }

            for (int i = 58; i <= n; i++) {
                x3 = x3 * 2 + (s[i] - '0');
            }

            auto full = [&](string s) {
                string pad = s;
                while (pad.size() < 11) pad += " ";
                i64 val = 0;
                for (char c : pad) {
                    i64 cv = 0;
                    if (c == ' ')
                        cv = 0;
                    else if (c >= '0' && c <= '9')
                        cv = c - '0' + 1;
                    else if (c >= 'A' && c <= 'Z')
                        cv = c - 'A' + 11;
                    else if (c == '_')
                        cv = 37;
                    val = val * 38 + cv;
                }
                return val;
            };

            auto get = [&](i64 x) {
                string ans;
                i64 tp = 36 * 10 * 26 * 26 * 26;
                for (int i = 1; i <= 6; i++) {
                    if (i == 1) {
                        auto gt2 = [&](i64 val) {
                            if (val == 0)
                                return char(' ');
                            else if (val <= 10)
                                return char('0' + val - 1);
                            return char('A' + val - 11);
                        };
                        ans += gt2(x / tp);
                        x %= tp;
                        tp /= 36;
                    } else if (i == 2) {
                        auto gt2 = [&](i64 val) {
                            if (val <= 9) return char('0' + val);
                            return char('A' + val - 10);
                        };
                        ans += gt2(x / tp);
                        x %= tp;
                        tp /= 10;
                    } else if (i == 3) {
                        auto gt2 = [&](i64 val) { return char('0' + val); };
                        ans += gt2(x / tp);
                        x %= tp;
                        tp /= 26;
                    } else {
                        auto gt2 = [&](i64 val) { return char('A' + val); };
                        ans += gt2(x / tp);
                        x %= tp;
                        tp /= 26;
                    }
                }
                reverse(ans.begin(), ans.end());
                while (ans.size() && ans.back() == ' ') ans.pop_back();
                reverse(ans.begin(), ans.end());
                return ans;
            };

            if (x1 >= (1ll << 25) && x2 >= (1ll << 25)) {
                x1 -= (1ll << 25);
                x2 -= (1ll << 25);

                string s1 = get(x1), s2 = get(x2);
                x1 = full(s1);
                x2 = full(s2);
                i64 a1 = getsanlie(x1, 12);
                i64 a2 = getsanlie(x1, 25);
                i64 a3 = getsanlie(x2, 12);
                i64 a4 = getsanlie(x2, 25);

                mp12[a1].push_back(s1);
                mp25[a2].push_back(s1);
                mp12[a3].push_back(s2);
                mp25[a4].push_back(s2);

                res1 = s1, res2 = s2;
            } else if (x1 >= (1ll << 25)) {
                x1 -= (1ll << 25);
                string s1 = get(x1);
                x1 = full(s1);
                i64 a1 = getsanlie(x1, 12);
                i64 a2 = getsanlie(x1, 25);

                res1 = s1;

                if (mp25[x2].empty()) {
                    res2 = "###";
                } else {
                    res2 = "#";
                    res2 += mp25[x2].back();
                }

                mp12[a1].push_back(s1);
                mp25[a2].push_back(s1);
            } else if (x2 >= (1ll << 25)) {
                x2 -= (1ll << 25);
                string s2 = get(x2);
                x2 = full(s2);
                i64 a3 = getsanlie(x2, 12);
                i64 a4 = getsanlie(x2, 25);

                if (mp25[x1].empty()) {
                    res1 = "###";
                } else {
                    res1 = "#";
                    res1 += mp25[x1].back();
                }
                res2 = s2;

                mp12[a3].push_back(s2);
                mp25[a4].push_back(s2);
            } else {
                if (mp25[x1].empty()) {
                    res1 = "###";
                } else {
                    res1 = "#";
                    res1 += mp25[x1].back();
                }

                if (mp25[x2].empty()) {
                    res2 = "###";
                } else {
                    res2 = "#";
                    res2 += mp25[x2].back();
                }
            }

            if (x3) {
                res3 = x3;
            }
        }

        while (res1.size() > 1 && res1.back() == ' ') res1.pop_back();
        reverse(res1.begin(), res1.end());
        while (res1.size() > 1 && res1.back() == ' ') res1.pop_back();
        reverse(res1.begin(), res1.end());

        while (res2.size() > 1 && res2.back() == ' ') res2.pop_back();
        reverse(res2.begin(), res2.end());
        while (res2.size() > 1 && res2.back() == ' ') res2.pop_back();
        reverse(res2.begin(), res2.end());

        cout << res1 << ' ' << res2;

        if (res3) {
            cout << ' ' << res3 << '\n';
        } else {
            cout << '\n';
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
