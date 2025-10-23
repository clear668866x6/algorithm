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

//线段树支持反转操作

int rev[N];
struct E{
    int l,r,s;
}tr[N<<2];
int n,q,w[N];

void puhsup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r)return tr[u]={l,r,w[l]},void();

    int mid=l+r>>1;

    build(u<<1,l,mid),build(u<<1|1,mid+1,r);

    pushup(u);
}

int query(int u,int l,int r,int dep){
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u].sum;
    }

    int mid=tr[u].l+tr[u].r>>1,res=0;

    if(l<=mid)res+=query(u<<1|rev[dep],l,r,dep-1);
    if(r>mid)res+=query(u<<1|rev[dep]^1,l,r,dep-1);
    return res;

}

void solve() {
    cin>>n>>q;
    
    FOR(i,1,n)cin>>w[i];

    build(1,1,n);

    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            
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