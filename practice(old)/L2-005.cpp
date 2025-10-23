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
constexpr int N = 50 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
set<int>s[N];
int nc[60][60],nt[60][60];

void solve() {
    cin>>n;

    FOR(i,1,n){
        int k,x;
        cin>>k;
        while(k--){
            cin>>x;
            s[i].insert(x);
        }
    }

    FOR(i,1,n){
        FOR(j,i+1,n){
            set<int>p,q;
            int cnt=0;
            for(auto x:s[i]){
                p.insert(x);
                q.insert(x);
            }
            for(auto y:s[j]){
                if(q.count(y)){
                    cnt++;
                }
                p.insert(y);
                
            }
            nt[i][j]=p.sz;
            nc[i][j]=cnt;
        }
    }

    int q;
    cin>>q;

    while(q--){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        printf("%.2lf\%\n",(double)nc[a][b]/(double)nt[a][b]*100.);
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}