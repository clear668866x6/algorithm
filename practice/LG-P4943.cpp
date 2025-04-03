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

int n,m,k;
int c[N];
VPII g[N];
int d1[N],d2[N],d3[N];

void dijistra1(int x,int d[]){
    priority_queue<PII,VPII,greater<PII>>q;

    d[x]=0;

    q.push({0,x});

    VI vis(n+1,0);

    while(q.sz){
        int ver=q.top().se;
        q.pop();

        if(vis[ver])continue;
        vis[ver]=1;

        for(auto& [j,w]:g[ver]){
            if(d[j]>d[ver]+w){
                d[j]=d[ver]+w;
                q.push({d[j],j});
            }
        }
    }
}

void dijistra2(int x,int d[]){
    priority_queue<PII,VPII,greater<PII>>q;

    d[x]=0;

    q.push({0,x});

    VI vis(n+1,0);

    while(q.sz){
        int ver=q.top().se;
        q.pop();

        if(vis[ver])continue;
        vis[ver]=1;

        for(auto& [j,w]:g[ver]){
            if(c[j])continue;
            if(d[j]>d[ver]+w){
                d[j]=d[ver]+w;
                q.push({d[j],j});
            }
        }
    }
}

void cha(){
    FOR(i,1,n){
        d1[i]=d2[i]=d3[i]=1e18;
    }
}

void solve() {
    cin>>n>>m>>k;

    FOR(i,1,k){
        int x;
        cin>>x;
        c[x]=1;
    }

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    int x,y;

    cin>>x>>y;

    int ans=1e18;

    cha();
    dijistra1(x,d1);
    
    ans=min(ans,d1[y]+d1[1]);
    cha();
    dijistra1(y,d1);
    ans=min(ans,d1[x]+d1[1]);
    cha();
    dijistra1(1,d2);
    dijistra2(1,d3);
    int t=max(d2[x],d3[y]);
    t=min(t,max(d2[y],d3[x]));
    cout<<min(ans,t)<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}