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

int n,m,p[N];
struct E{
    int x,y;
}e[N];
bool vis[N];

int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}

void uni(int a,int b){
    int pa=find(a),pb=find(b);
    if(pa!=pb){
        p[pa]=pb;
    }
}

void solve() {
    cin>>n>>m;

    int tot=0;

    FOR(i,1,n)p[i]=i;

    FOR(i,1,m){
        int a,b;
        cin>>a>>b;
        a++,b++;
        e[i]={a,b};
        uni(a,b);
    }

    FOR(i,1,n){
        if(i==find(i))tot++;
    }

    int k;
    cin>>k;

    while(k--){
        int x;
        cin>>x;
        x++;
        vis[x]=1;

        FOR(i,1,n)p[i]=i;

        FOR(i,1,m){
            if(vis[e[i].x]||vis[e[i].y])continue;
            uni(e[i].x,e[i].y);
        }

        int num=0;

        FOR(i,1,n){
            if(i==p[i])num++;
        }

        // cout<<num<<' '<<tot<<endl;

        if(num==tot||num==tot+1){
            printf("City %lld is lost.\n",x-1);
        }else{
			printf("Red Alert: City %lld is lost!\n",x-1);
        }
        tot=num;
    }

    int num=0;
    FOR(i,1,n){
        if(i==p[i])num++;
    }

    if(num==n){
        printf("Game Over.");
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}