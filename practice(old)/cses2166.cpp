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

int n,m,w[N];
struct E{
    int l,r;
    int sum;
    int lsum,rsum;
    int tsum;
}tr[N<<2];

void pushup(E& u,E& l,E& r){
    u.sum=l.sum+r.sum;
    u.lsum=max(l.sum+r.lsum,l.lsum);
    u.rsum=max(r.sum+l.rsum,r.rsum);
    u.tsum=max({l.tsum,r.tsum,l.rsum+r.lsum});
}

void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r){
        tr[u]={l,r,w[l],w[l],w[l],w[l]};
        RE;
    }
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int x,int v){
    if(tr[u].l==tr[u].r){
        tr[u]={tr[u].l,tr[u].l,v,v,v,v};
        RE;
    }

    int mid=tr[u].l+tr[u].r>>1;
    if(x<=mid)modify(u<<1,x,v);
    else modify(u<<1|1,x,v);
    pushup(u);
}

E query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u];
    }
    int mid=tr[u].l+tr[u].r>>1;
    int v=-1e18;

    if(l>mid)return query(u<<1|1,l,r);
    if(r<=mid)return query(u<<1,l,r);

    E L=query(u<<1,l,r);
    E R=query(u<<1|1,l,r);
    E res;
    pushup(res,L,R);
    return res;
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    build(1,1,n);

    while(m--){
        int op,a,b;
        cin>>op;
        if(op==1){
            cin>>a>>b;
            modify(1,a,b);
        }else{
            cin>>a>>b;
            cout<<max<int>(0,query(1,a,b).lsum)<<endl;
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