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
// #define sz size()/
constexpr int N = 300 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,k;
char s[N][N];
struct E{
    int x,y,s,sz;
};
int dx[]={-1,0,1,0,0};
int dy[]={0,1,0,-1,0};
bool vis[N][N];

bool check(int x,int y,int sz){
    if(vis[x][y])return false;
    FOR(i,x-sz,x+sz){
        FOR(j,y-sz,y+sz){
            if(i<1||j<1||i>n||j>n||s[i][j]=='*')return false;
        }
    }
    return true;
}

int calc(int x){
    if(x<k)return 2;
    if(x<2*k)return 1;
    return 0;
}

void solve() {
    cin>>n>>k;

    FOR(i,1,n){
        FOR(j,1,n){
            cin>>s[i][j];
        }
    }

    queue<E>q;
    
    q.push({3,3,0,2});
    vis[3][3]=1;

    while(q.size()){
        auto [x,y,S,sz]=q.front();
        q.pop();

        if(x==n-2&&y==n-2){
            cout<<S;
            RE;
        }

        FOR(i,0,4){
            int a=dx[i]+x,b=dy[i]+y;
            if(dx[i]==0&&dy[i]==0){
                q.push({a,b,S+1,calc(S+1)});
            }
            if(check(a,b,sz)){
                vis[a][b]=1;
                q.push({a,b,S+1,calc(S+1)});
            }
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