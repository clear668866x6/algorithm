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
constexpr int N = 1e6 + 10;
constexpr int mod = 1e9 + 7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

//哈希线段树
int h[N];
unsigned long long p[N];
struct E{
    int l,r;
    unsigned long long h1,h2;
    E operator+(const E& t){
        return {l,t.r,(h1*p[t.r-t.l+1]+t.h1)%mod,(h2+p[r-l+1]*t.h2)%mod};
    }
}tr[N<<2];
string s;
int n,q;

void pushup(int u){
    tr[u]=tr[u<<1]+tr[u<<1|1];
}

void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r)return tr[u].h1=tr[u].h2=s[l],void();
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int k,int v){
    if(tr[u].l==tr[u].r)return tr[u].h2=tr[u].h1=v,void();
    int mid=tr[u].l+tr[u].r>>1;
    if(k<=mid)modify(u<<1,k,v);
    else modify(u<<1|1,k,v);
    pushup(u);
}

E query(int u,int l,int r){
    // if(tr[u].l>r||tr[u].r<l)return E{};
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u];
    }

    int mid=tr[u].l+tr[u].r>>1;

    if(r<=mid)return query(u<<1,l,r);
    if(l>mid)return query(u<<1|1,l,r);

    return query(u<<1,l,r)+query(u<<1|1,l,r);
}

void solve() {
    cin>>n>>q>>s;
    p[0]=1;
    s=' '+s;

    FOR(i,1,n){
        p[i]=(p[i-1]*131)%mod;
    }
    build(1,1,n);

    while(q--){
        int op,a,b;
        cin>>op>>a;
        if(op==1){
            char c;
            cin>>c;
            modify(1,a,c);
        }else{
            cin>>b;
            E ans=query(1,a,b);
            if(ans.h1==ans.h2){
                YES;
            }else{
                NO;
            }
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