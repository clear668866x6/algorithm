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

int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
string s[]={"U","RU","R","RD","D","LD","L","LU"};
string a,b;
bool vis[10][10];
TII pre[10][10];
int x_1,y_1;
struct E{
    int l,r,step;
    bool operator<(const E& t)const{
        return step>t.step;
    }
};

void dfs(int x,int y){
    if(x==x_1&&y==y_1)RE;
    auto [a,b,t]=pre[x][y];
    dfs(a,b);
    cout<<s[t]<<endl;
}

void solve() {
    cin>>a>>b;
    int x1=a[0]-'a'+1,y1=a[1]-'0';
    int x2=b[0]-'a'+1,y2=b[1]-'0';
    x_1=x1,y_1=y1;
    priority_queue<E>q;
    q.push({x1,y1,0});
    vis[x1][y1]=1;

    while(q.sz){
        auto [x,y,step]=q.top();
        q.pop();

        if(x==x2&&y==y2){
            cout<<step<<endl;
            break;
        }

        FOR(i,0,7){
            int a=dx[i]+x,b=dy[i]+y;
            if(a<1||b<1||a>8||b>8||vis[a][b])continue;
            vis[a][b]=1;
            pre[a][b]={x,y,i};
            q.push({a,b,step+1});
        }
    }
    dfs(x2,y2);
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}