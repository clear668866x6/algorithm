#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
using PII = pair<int, int>;
using TII = tuple<int, int, int>;
#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define BSI basic_string<int>
#define BSPI basic_string<PII>
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define VI vector<int>
#define VII vector<vector<int>>
#define VPII vector<PII>
#define lowbit(x) ((x)&(-x))
#define RE return;
#define RET return true;
#define REF return false;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define fi first
#define se second
#define sz size()
constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n1,n2,m1,m2;
int a[110][110];
int b[110][110];
int c[110][110];

void solve() {
    cin>>n1>>m1;

    FOR(i,1,n1){
        FOR(j,1,m1){
            cin>>a[i][j];
        }
    }

    cin>>n2>>m2;

    FOR(i,1,n2){
        FOR(j,1,m2){
            cin>>b[i][j];
        }
    }
    if(m1!=n2){
        cout<<"Error: "<<m1<<" != "<<n2<<endl;
        RE;
    }



    FOR(i,1,n1){
        FOR(j,1,m2){
            FOR(k,1,n2){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j]);
            }
        }
    }

    cout<<n1<<' '<<m2<<endl;

    FOR(i,1,n1){
        FOR(j,1,m2){
            cout<<c[i][j]<<" \n"[j==m2];
        }
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}