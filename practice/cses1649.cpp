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
int w[N];

struct E{
    int l,r;
    int mn;
}tr[N<<2];

void pushup(int u){
    tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
}

void build(int u,int l,int r){
    tr[u]={l,r,(int)1e18};
    if(l==r){
        tr[u]={l,r,w[l]};
        RE;
    }

    int mid=l+r>>1;

    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int x,int v){
    if(tr[u].l==tr[u].r){
        tr[u].mn=v;
        RE;
    }

    int mid=tr[u].l+tr[u].r>>1;

    if(x<=mid)modify(u<<1,x,v);
    else modify(u<<1|1,x,v);
    pushup(u);
}

int query(int u,int l,int r){
    if(tr[u].l>r||tr[u].r<l)return 1e18;
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u].mn;
    }

    return min(query(u<<1,l,r),query(u<<1|1,l,r));
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    build(1,1,n);

    while(m--){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            modify(1,a,b);
        }else{
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