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

int w[N];
__int128 s[N];
int n;

void solve() {
    FOR(i,1,2e5)w[i]=i,s[i]=s[i-1]+w[i]*w[i];

    cin>>n;

    FOR(i,1,1e5){
        __int128 t1=s[i+n]-s[i-1],t2=s[i+2*n]-s[i+n];
        // FOR(j,i,i+n){
        //     t1=t1+w[j]*w[j];
        // }
        // FOR(j,i+n+1,i+2*n){
        //     t2=t2+w[j]*w[j];
        // }
        if(t1==t2){
            FOR(j,i,i+n){
                if(j!=i+n){
                    cout<<w[j]<<"^2 + ";
                }else{
                    cout<<w[j]<<"^2 ="<<endl;
                }
            }
            FOR(j,i+n+1,i+2*n){
                if(j!=i+2*n){
                    cout<<w[j]<<"^2 + ";
                }else{
                    cout<<w[j]<<"^2";
                }
            }
            RE;
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