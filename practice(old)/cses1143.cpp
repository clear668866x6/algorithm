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
    int l,r;
    int mx;
}tr[N<<2];
int w[N];

void pushup(int u){
    tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
}

void build(int u,int l,int r){
    tr[u]={l,r,0};
    if(l==r){
        tr[u]={l,r,w[l]};
        RE;
    }

    int mid=l+r>>1;

    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int v){
    if(tr[u].l>r||tr[u].r<l)RE;
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].mx-=v;
        RE;
    }

    modify(u<<1,l,r,v);
    modify(u<<1|1,l,r,v);
    pushup(u);
}

int getans(int u,int l,int r,int v){
    if(l==r){
        if(tr[u].mx>=v)return l;
        return -1;
    }

    int mid=l+r>>1;
    if(tr[u<<1].mx>=v)return getans(u<<1,l,mid,v);
    if(tr[u<<1|1].mx>=v)return getans(u<<1|1,mid+1,r,v);
    return -1;
}
//线段树维护下标最小的并且大于等于x的

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    build(1,1,n);

    while(m--){
        int x;
        cin>>x;
        if(tr[1].mx<x){
            cout<<0<<' ';
        }else{
            int idx=getans(1,1,n,x);
            if(idx==-1)idx=0;
            cout<<idx<<' ';
            if(idx>0)modify(1,idx,idx,x);
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