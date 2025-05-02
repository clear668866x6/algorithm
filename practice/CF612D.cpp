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
constexpr int N = 2e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,k;
int b[N*2],cnt;
PII w[N],ans[N];
int c1[N*2],c2[N*2],tot;

void solve() {
    cin>>n>>k;

    FOR(i,1,n){
        int l,r;
        cin>>l>>r;
        b[++cnt]=l,b[++cnt]=r;
        w[i]={l,r};
    }

    sort(b+1,b+1+cnt);

    FOR(i,1,n){
        w[i].fi=lower_bound(b+1,b+1+cnt,w[i].fi)-b;
        w[i].se=lower_bound(b+1,b+1+cnt,w[i].se)-b;
    }

    FOR(i,1,n){
        c1[w[i].fi]++;
        c2[w[i].se]--;
    }

    int now=0;
    bool f=false;

    FOR(i,1,cnt){
        now+=c1[i];
        if(now>=k&&!f)ans[++tot].fi=i,f=1;
        now+=c2[i];
        if(now<k&&f)ans[tot].se=i,f=0;
    }

    cout<<tot<<endl;
    
    FOR(i,1,tot)cout<<b[ans[i].fi]<<' '<<b[ans[i].se]<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}