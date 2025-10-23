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

int n,m,q;
int p[N];
int t[N],siz[N];
//很奇怪的并查集，居然不需要路径压缩（因为它在后面修改，因为它的路径压缩跟时间有关）
int find(int x){
    if(p[x]!=x)x=find(p[x]);
    return p[x];
}

void add(int x,int y,int ti){
    x=find(x),y=find(y);
    if(x==y)RE;
    if(siz[x]>siz[y])swap(x,y);
    siz[y]+=siz[x],p[x]=y,t[x]=ti;
}

int merge(int a,int b){
    int res=-1;
    while(a!=b){
        int& x=t[a]<t[b]?a:b;
        res=t[x];
        x=p[x];//在这里修改，所以不需要路径压缩
        if(res==1e18)return -1;
    }
    return res;
}

void solve() {
    cin>>n>>m>>q;

    FOR(i,1,n)p[i]=i,siz[i]=1,t[i]=1e18;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        add(a,b,i);
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<endl;
        }else{
            cout<<merge(x,y)<<endl;
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