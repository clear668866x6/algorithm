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

int n,s,m,k;
int w[N],b[N];

bool check(){
    FOR(i,1,n){
        if(w[i]!=b[i])return 0;
    }
    return 1;
}

void solve() {
    cin>>n>>s>>m>>k;

    FOR(i,1,n)cin>>w[i],b[i]=w[i];
    
    int t=0;
    do{
        t++;
        swap(b[s],b[m]);
        int t=b[1];
        FOR(i,2,n){
            b[i-1]=b[i];
        }
        b[n]=t;
    }while(!check());

    k%=t;

    while(k--){
        swap(w[s],w[m]);
        int t=w[1];
        FOR(i,2,n){
            w[i-1]=w[i];
        }
        w[n]=t;
    }

    FOR(i,1,n)cout<<w[i]<<" ";

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}