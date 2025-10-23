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
VI g[N];
int d[N],dist[N];
int pa[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        g[b].emplace_back(a);
        d[a]++;
    }

    queue<int>q;

    FOR(i,1,n){
        if(!d[i]){
            q.push(i);
        }
    }

    FOR(i,1,n){
        dist[i]=-1e18;
    }

    dist[n]=1;

    while(q.sz){
        int t=q.front();
        q.pop();

        for(auto& j:g[t]){
            if(dist[j]<dist[t]+1){
                dist[j]=dist[t]+1;
                pa[j]=t;
            }
            if((--d[j])==0){
                q.push(j);
            }
        }
    }

    if(dist[1]<0){
        cout<<"IMPOSSIBLE"<<endl;
        RE;
    }

    int x=1;

    cout<<dist[1]<<endl;
    while(n!=x){
        cout<<x<<' ';
        x=pa[x];
    }
    cout<<n<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}