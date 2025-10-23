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
constexpr int N = 6;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,w[N];

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    sort(w+1,w+1+n);

    VI p;

    do{
        int ans=0;
        FOR(i,1,n){
            ans=ans*10+w[i];
        }

        p.pb(ans);
        
    }while(next_permutation(w+1,w+1+n));

    int tot=p.sz;
    
    FOR(i,0,(1<<tot)-1){
        VI vis(tot+1,0);
        int cnt=0;
        FOR(j,0,tot-1){
            if(i>>j&1){
                cnt++;
                vis[j]=1;
            }
        }
        if(2*cnt==tot){
            int t1=0,t2=0;
            FOR(i,0,tot-1){
                if(vis[i]){
                    t1+=p[i]*p[i];
                }else{
                    t2+=p[i]*p[i];
                }
            }
            if(t1==t2){
                FOR(i,0,tot-1){
                    if(vis[i]){
                        cout<<p[i]<<endl;
                    }
                }
                RE;
            }
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