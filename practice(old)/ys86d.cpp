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
constexpr int N = 2e3 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m,cnt;
char s[N][N];
bool vis[N][N];
map<int,VPII>mp;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void dfs(int x,int y,int cnt){
    vis[x][y]=1;
    mp[cnt].emplace_back(x,y);
    FOR(i,0,3){
        int a=x+dx[i],b=y+dy[i];
        if(a<1||b<1||a>n||b>m||vis[a][b]||s[a][b]=='*')continue;
        dfs(a,b,cnt);
    }
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>s[i][j];
        }
    }

    int ans=0;

    FOR(i,1,n){
        FOR(j,1,m){
            if(s[i][j]=='.'&&!vis[i][j]){
                dfs(i,j,++cnt);
                map<int,int>mp2,mp3;
                int ct=mp[cnt].sz;
                for(auto [x,y]:mp[cnt]){
                    mp2[x]++;
                    mp3[y]++;
                }
                if((mp2.sz)*(mp3.sz)==ct){
                    ans++;
                }
            }
        }
    }
    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}