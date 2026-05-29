#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 1e9 + 7;

void solve() {
    int q;
    cin >> q;

    map<string, vector<string>> mp;
    map<string, int> mp2;
    map<string, int> mp3;

    auto dfs = [&](auto &&dfs, string &p, string &s1, map<string, int> &tmp) -> void {
        for (auto v : mp[p]) {
            if (v[0] == '$') {
                string tmp2 = v.substr(1);
                if (mp3[tmp2] == 1) {
                    mp2[s1] += tmp[tmp2];
                    mp2[s1] %= mod;
                } else {
                    dfs(dfs, tmp2, s1, tmp);
                }
            } else {
                mp2[s1] += v.size();
                mp2[s1] %= mod;
            }
        }
    };
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            string s1, s2, s, ans;
            cin >> s1;
            cin.ignore();
            getline(cin, s2);
            stringstream ss;
            ss << s2;
            map<string, int> tmp2 = mp2;
            mp2[s1] = 0;
            while (ss >> s) {
                if (s[0] == '$') {
                    string tmp = s.substr(1);
                    if (mp3[tmp] == 1) {
                        mp2[s1] += tmp2[tmp];
                        mp2[s1] %= mod;
                    } else {
                        dfs(dfs, tmp, s1, tmp2);
                    }
                } else {
                    mp2[s1] += s.size();
                    mp2[s1] %= mod;
                }
            }
            mp3[s1] = 1;
        } else if (op == 2) {
            string s1, s2, s, ans;
            cin >> s1;
            cin.ignore();
            getline(cin, s2);
            stringstream ss;
            ss << s2;
            mp[s1].clear();
            while (ss >> s) {
                mp[s1].push_back(s);
            }
            mp3[s1] = 2;

        } else {
            string s;
            cin >> s;
            if (mp3[s] == 1) {
                cout << mp2[s] << '\n';
            } else {
                map<string, int> tmp2 = mp2;
                dfs(dfs, s, s, tmp2);
                cout << mp2[s] << '\n';
                mp2[s] = 0;
            }
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