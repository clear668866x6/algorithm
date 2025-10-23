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

int n,m,k,s;
struct E{
    int t,c,id,v;
    bool operator<(const E& t)const{
        return v<t.v;
    }
}w[N];
int a[N],b[N];
PII ans[N];

bool check(int x){
    int m1=1e18,m2=1e18,d1=1,d2=1;

    FOR(i,1,x){
        if(a[i]<m1)m1=a[i],d1=i;
        if(b[i]<m2)m2=b[i],d2=i;
    }

    int sum=0;

    FOR(i,1,m){
        if(w[i].t==1)w[i].v=m1*w[i].c;
        else w[i].v=m2*w[i].c;
    }

    sort(w+1,w+1+m);

    FOR(i,1,k){
        sum+=w[i].v;
    }

    if(sum>s){
        return false;
    }

    FOR(i,1,k){
        if(w[i].t==1)ans[i]={w[i].id,d1};
        else ans[i]={w[i].id,d2};
    }

    return true;

}

void solve() {
    cin>>n>>m>>k>>s;

    FOR(i,1,n)cin>>a[i];
    FOR(i,1,n)cin>>b[i];

    FOR(i,1,m)cin>>w[i].t>>w[i].c,w[i].id=i;

    int l=0,r=n+1;

    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    
    if(r==n+1||r<=0){
        cout<<-1<<endl;
        RE;
    }
    
    cout<<r<<endl;

    FOR(i,1,k){
        cout<<ans[i].fi<<' '<<ans[i].se<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}