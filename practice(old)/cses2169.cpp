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
constexpr int N = 5e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int a1[N],a2[N];
struct E{
    int l,r,id;
    bool operator<(const E& t)const{
        if(l==t.l)return r>t.r;
        return l<t.l;
    }
}w[N];
int b[N],cnt;
int tr[N];

void add(int x,int c){
    for(int i=x;i<N;i+=lowbit(i))tr[i]+=c;
}

int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}

void solve() {
    cin>>n;

    set<int>s;
    map<int,int>b;
    
    FOR(i,1,n){
        int x,y;
        cin>>x>>y;
        w[i]={x,y,i};
        s.insert(x),s.insert(y);
    }

    s.insert(0);
    s.insert(1e18);

    for(auto x:s)b[x]=++cnt;
    
    FOR(i,1,n){
        w[i].l=b[w[i].l];
        w[i].r=b[w[i].r];
    }

    sort(w+1,w+1+n);
    
    FOR(i,1,n){
        a1[w[i].id]=query(cnt)-query(w[i].r-1);
        add(w[i].r,1);
    }

    FOR(i,1,n){
        add(w[i].r,-1);
        a2[w[i].id]=query(w[i].r)-query(w[i].l);
    }

    FOR(i,1,n)cout<<a2[i]<<" \n"[i==n];
    FOR(i,1,n)cout<<a1[i]<<" \n"[i==n];

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}