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

int n,m;
int w[N];

struct E{
    int l,r;
    int sum,tag,jyz;
}tr[N<<2];

void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u){
    if(tr[u].jyz>=0){
        tr[u<<1].sum=(tr[u<<1].r-tr[u<<1].l+1)*tr[u].jyz;
        tr[u<<1|1].sum=(tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].jyz;
        tr[u<<1].tag=tr[u<<1|1].tag=0;
        tr[u<<1].jyz=tr[u<<1|1].jyz=tr[u].jyz;
        tr[u].jyz=-1;
    }
    if(tr[u].tag){
        tr[u<<1].sum+=(tr[u<<1].r-tr[u<<1].l+1)*tr[u].tag;
        tr[u<<1|1].sum+=(tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].tag;
        tr[u<<1].tag+=tr[u].tag;
        tr[u<<1|1].tag+=tr[u].tag;
        tr[u].tag=0;
    }
}

void build(int u,int l,int r){
    tr[u]={l,r,0,0,-1};
    if(l==r){
        tr[u]={l,r,w[l],0,-1};
        RE;
    }
    pushdown(u);
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int op,int v){
    if(tr[u].l>r||tr[u].r<l)RE;
    if(tr[u].l>=l&&tr[u].r<=r){
        if(op==1){
            pushdown(u);
            tr[u].tag+=v;
            tr[u].sum+=(tr[u].r-tr[u].l+1)*tr[u].tag;
        }else{
            tr[u].tag=0;
            tr[u].jyz=v;
            tr[u].sum=(tr[u].r-tr[u].l+1)*tr[u].jyz;
        }
        RE;
    }
    pushdown(u);
    modify(u<<1,l,r,op,v);
    modify(u<<1|1,l,r,op,v);
    pushup(u);
}

int query(int u,int l,int r){
    if(tr[u].l>r||tr[u].r<l)return 0;
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    pushdown(u);
    return query(u<<1,l,r)+query(u<<1|1,l,r);
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    build(1,1,n);

    while(m--){
        int op,a,b,x;
        cin>>op;
        if(op==1){
            cin>>a>>b>>x;
            modify(1,a,b,1,x);
        }else if(op==2){
            cin>>a>>b>>x;
            modify(1,a,b,2,x);
        }else{
            cin>>a>>b;
            cout<<query(1,a,b)<<endl;
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