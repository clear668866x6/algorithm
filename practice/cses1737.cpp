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

//可持久化线段树模板
struct E{
    int l,r,sum;
}tr[N*40];
int n,m,w[N];
int cnt,cur=1;

void modify(int& rt,int k,int v,int l=0,int r=n-1){
    tr[cur]={tr[rt].l,tr[rt].r,tr[rt].sum+v};
    rt=cur,cur++;

    if(l==r){
        RE;
    }

    int mid=l+r>>1;

    if(k<=mid)modify(tr[rt].l,k,v,l,mid);
    else modify(tr[rt].r,k,v,mid+1,r);
}

int query(int u,int l,int r,int L=0,int R=n-1){
    if(L>=l&&R<=r){
        return tr[u].sum;
    }

    int mid=L+R>>1;

    int res=0;

    if(l<=mid)res+=query(tr[u].l,l,r,L,mid);
    if(r>mid)res+=query(tr[u].r,l,r,mid+1,R);
    return res;
}

void solve() {
    cin>>n>>m;

    FOR(i,0,n-1)cin>>w[i];
    
    VI ver;
    ver.pb(0);

    FOR(i,0,n-1){
        modify(ver[0],i,w[i]);
    }

    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int k,a,x;
            cin>>k>>a>>x;
            k--;
            a--;
            modify(ver[k],a,x-query(ver[k],a,a));
        }else if(op==2){
            int k,a,b;
            cin>>k>>a>>b;
            k--,a--,b--;
            cout<<query(ver[k],a,b)<<endl;
        }else{
            int k;
            cin>>k;
            ver.pb(ver[k-1]);
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