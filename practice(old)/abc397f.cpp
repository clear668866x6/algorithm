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
constexpr int N = 3e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,w[N];
int pre[N],suf[N],lst[N],vis[N];
struct E{
    int l,r;
    int v,tag;
}tr[N<<2];

void pushup(int u){
    tr[u].v=max(tr[u<<1].v,tr[u<<1|1].v);
}

void pushdown(int u){
    if(tr[u].tag){
        tr[u<<1].v+=tr[u].tag;
        tr[u<<1|1].v+=tr[u].tag;
        tr[u<<1].tag+=tr[u].tag;
        tr[u<<1|1].tag+=tr[u].tag;
        tr[u].tag=0;
    }
}

void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r)RE;

    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int v){
    if(tr[u].l>r||tr[u].r<l)RE;
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].v+=v;
        tr[u].tag+=v;
        RE;
    }

    pushdown(u);
    modify(u<<1,l,r,v);
    modify(u<<1|1,l,r,v);
    pushup(u);
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n){
        pre[i]=pre[i-1]+(vis[w[i]]==0);
        lst[i]=vis[w[i]];
        vis[w[i]]=i;
    }
    memset(vis,0,sizeof vis);

    FORD(i,1,n){
        suf[i]=suf[i+1]+(vis[w[i]]==0);
        vis[w[i]]=i;
    }

    int ans=0;

    build(1,1,n);

    FOR(i,1,n-1){
        ans=max(ans,suf[i+1]+tr[1].v);
        modify(1,i,i,pre[i]);
        modify(1,lst[i+1],i,1);
    }
    cout<<ans;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}