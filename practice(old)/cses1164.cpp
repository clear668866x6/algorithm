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

int n,cnt;
struct E{
    int x,v,id;
    bool operator<(const E& t)const{
        if(x==t.x)return v>t.v;
        return x<t.x;
    }
}w[N*2];
int ans[N];
VI p;

void solve() {
    cin>>n;
    
    FOR(i,1,n){
        int a,b;
        cin>>a>>b;
        w[++cnt]={a,1,i};
        w[++cnt]={b,-1,i};
    }

    sort(w+1,w+1+cnt);

    FORD(i,1,n){
        p.pb(i);
    }

    int r=0;

    FOR(i,1,cnt){
        if(w[i].v==1){
            ans[w[i].id]=p.back();
            p.pop_back();
            r=max(r,ans[w[i].id]);
        }else{
            p.pb(ans[w[i].id]);
        }
    }

    cout<<r<<endl;
    FOR(i,1,n)cout<<ans[i]<<' ';

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}