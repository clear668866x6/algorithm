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

int n,m;
struct E{
    int l,r,sum,tag;
}tr1[N<<2],tr2[N<<2];
int w[N];

void pushup1(int u){
    tr1[u].sum=tr1[u<<1].sum+tr1[u<<1|1].sum;
}

void pushup2(int u){
    tr2[u].sum=tr2[u<<1].sum+tr2[u<<1|1].sum;
}

void pushdown1(int u){
    int l=tr1[u].l,r=tr1[u].r;
    int mid=l+r>>1;
    if(tr1[u].tag==0)RE;
    tr1[u<<1].sum+=(mid-l+1)*tr1[u].tag;
    tr1[u<<1|1].sum+=(r-mid)*tr1[u].tag;
    tr1[u<<1].tag+=tr1[u].tag;
    tr1[u<<1|1].tag+=tr1[u].tag;
    tr1[u].tag=0;
}

void pushdown2(int u){
    int l=tr2[u].l,r=tr2[u].r;
    int mid=l+r>>1;
    if(tr2[u].tag==0)RE;
    tr2[u<<1].sum+=(mid-l+1)*(l+mid)*tr2[u].tag/2;
    tr2[u<<1|1].sum+=(r-mid)*(mid+1+r)*tr2[u].tag/2;
    tr2[u<<1].tag+=tr2[u].tag;
    tr2[u<<1|1].tag+=tr2[u].tag;
    tr2[u].tag=0;
}

void build1(int u,int l,int r){
    tr1[u]={l,r};
    if(l==r){
        tr1[u]={l,r,w[l],0};
        RE;
    }

    int mid=l+r>>1;
    pushdown1(u);
    build1(u<<1,l,mid),build1(u<<1|1,mid+1,r);
    pushup1(u);
}

void build2(int u,int l,int r){
    tr2[u]={l,r};
    if(l==r){
        RE;
    }
    pushdown2(u);
    int mid=l+r>>1;
    build2(u<<1,l,mid),build2(u<<1|1,mid+1,r);
    pushup2(u);
}

void modify1(int u,int l,int r,int v){
    if(tr1[u].l>r||tr1[u].r<l)RE;
    if(tr1[u].l>=l&&tr1[u].r<=r){
        tr1[u].sum+=(tr1[u].r-tr1[u].l+1)*v;
        tr1[u].tag+=v;
        RE;
    }
    pushdown1(u);
    modify1(u<<1,l,r,v);
    modify1(u<<1|1,l,r,v);
    pushup1(u);
}

void modify2(int u,int l,int r){
    if(tr2[u].l>r||tr2[u].r<l)RE;
    if(tr2[u].l>=l&&tr2[u].r<=r){
        tr2[u].sum+=(tr2[u].l+tr2[u].r)*(tr2[u].r-tr2[u].l+1)/2;
        tr2[u].tag++;
        RE;
    }
    pushdown2(u);
    modify2(u<<1,l,r);
    modify2(u<<1|1,l,r);
    pushup2(u);
}

int query1(int u,int l,int r){
    if(tr1[u].l>r||tr1[u].r<l)return 0;
    if(tr1[u].l>=l&&tr1[u].r<=r){
        return tr1[u].sum;
    }
    pushdown1(u);
    return query1(u<<1,l,r)+query1(u<<1|1,l,r);
}

int query2(int u,int l,int r){
    if(tr2[u].l>r||tr2[u].r<l)return 0;
    if(tr2[u].l>=l&&tr2[u].r<=r){
        return tr2[u].sum;
    }
    pushdown2(u);
    return query2(u<<1,l,r)+query2(u<<1|1,l,r);
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    build1(1,1,n);
    build2(1,1,n);

    while(m--){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            modify1(1,a,b,1-a);
            modify2(1,a,b);
        }else{
            cout<<(query1(1,a,b)+query2(1,a,b))<<endl;
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