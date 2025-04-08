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
constexpr int N = 3e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n1,n2,m;
BSI g1[N],g2[N];
int d1[N],d2[N];

void dijistra(int type,int u,int d[]){
    priority_queue<PII,VPII,greater<PII>>q;

    VI vis(n1+n2+1,0);

    FOR(i,1,n1+n2)d[i]=1e18;
    d[u]=0;

    q.push({d[u],u});

    while(q.sz){
        int ver=q.top().se;
        q.pop();

        if(vis[ver])continue;
        vis[ver]=1;

        if(type==1){
            for(auto& j:g1[ver]){
                if(d[j]>d[ver]+1){
                    d[j]=d[ver]+1;
                    q.push({d[j],j});
                }
            }
        }else{
            for(auto& j:g2[ver]){
                if(d[j]>d[ver]+1){
                    d[j]=d[ver]+1;
                    q.push({d[j],j});
                }
            }
        }

    }
}

void solve() {
    cin>>n1>>n2>>m;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        if(a>n1||b>n1){
            g2[a]+=b;
            g2[b]+=a;
        }else{
            g1[a]+=b;
            g1[b]+=a;
        }
    }

    dijistra(1,1,d1);
    dijistra(2,n1+n2,d2);

    int ans=0;

    int t1=0,t2=0;

    FOR(i,1,n1)t1=max(t1,d1[i]);
    FOR(i,n1+1,n1+n2)t2=max(t2,d2[i]);

    cout<<t1+t2+1;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}