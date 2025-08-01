#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MAXN 1000010
#define debug cout<<"&"<<endl 
int primes[MAXN], cnt;
bool st[MAXN];
void gprimes (int n) {
    for (int i = 2;i <= n;i++) {
        if (!st[i])primes[cnt++] = i;
        for (int j = 0;primes[j] * i <= n;j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0)break;
        }
    }
}
void solve () {
    int n;
    cin >> n;
    vector<int> p (n + 1);
    for (int i = 0;primes[i] <= n;i++) {
        vector<int> a;
        for (int j = primes[i];j <= n;j += primes[i])
            if (!p[j])a.push_back (j);
        for (int j = 0;j < a.size ();j++)
            p[a[j]] = a[(j + 1) % a.size ()];
    }
    p[1] = 1;
    for (int i = 1;i <= n;i++)
        cout << p[i] << " ";
    cout << endl;
}
signed main () {
    ios;
    int t;
    gprimes (100000);
    cin >> t;
    while (t--)
        solve ();
    return 0;
}
