#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());
}