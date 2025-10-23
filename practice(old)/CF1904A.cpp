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

int a,b;

void solve() {
    int x1,y1,x2,y2;
    cin>>a>>b>>x1>>y1>>x2>>y2;

    VI dx(8,0),dy(8,0);

    dx[0]=a,dy[0]=b;
    dx[1]=-a,dy[1]=b;
    dx[2]=a,dy[2]=-b;
    dx[3]=-a,dy[3]=-b;
    dx[4]=b,dy[4]=a;
    dx[5]=-b,dy[5]=a;
    dx[6]=b,dy[6]=-a;
    dx[7]=-b,dy[7]=-a;

    int ans=0;

    map<PII,int>vis;

    FOR(i,0,7){
        int x=x1+dx[i],y=y1+dy[i];
        FOR(j,0,7){
            if(x+dx[j]==x2&&y+dy[j]==y2){
                if(vis[{x,y}])continue;
                vis[{x,y}]=1;
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}