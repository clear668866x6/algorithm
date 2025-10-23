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

int n;
struct E{
    int l,r;
}w[N];

int mn=1e18,mx,ans;

void dfs1(int u,int dep){
    if(u==-1){
        mn=min(mn,dep),mx=max(mx,dep);
        RE;
    }

    dfs1(w[u].l,dep+1),dfs1(w[u].r,dep+1);
}

int dfs2(int u,int dep){
    if(u==-1){
        if(dep==mn)return 0;//0 mn 1 mx 2 both
        return 1;
    }

    int x=dfs2(w[u].l,dep+1);
    int y=dfs2(w[u].r,dep+1);

    if((x==0&&y==1)||(x==2&&y==1)||(x==0&&y==2))ans++;
    if(x==2&&y==2){
        cout<<-1<<endl;
        exit(0);
    }
    
    if(x==2||y==2||x+y==1)return 2;
    if(x+y==0)return 0;
    return 1;
}

void solve() {
    cin>>n;

    FOR(i,1,n){
        int a,b;
        cin>>a>>b;
        w[i]={a,b};
    }

    dfs1(1,1);

    if(mx-mn>1){
        cout<<-1<<endl;
        RE;
    }

    if(mx==mn){
        cout<<0<<endl;
        RE;
    }

    dfs2(1,1);

    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}