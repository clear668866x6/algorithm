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
char s[8][8];
int ans;
VI x(8,0),y(8,0);
bool vis[10][10];
set<pair<VI,VI>>s1;//错误的，以后还是用位运算

void dfs(int u){
    if(u<k)RE;
    if(u==k){
        if(s1.count({x,y})){
            RE;
        }

        s1.insert({x,y});
        
        ans++;
        RE;
    }

    FOR(i,1,n){
        if(x[i])continue;
        x[i]=1;
        int c=0;
        VI l;
        FOR(j,1,m){
            if(y[j])continue;
            if(s[i][j]=='#'&&!vis[i][j]){
                c++;
                vis[i][j]=1;
                l.pb(j);
            }
        }
        dfs(u-c);
        FOR(j,1,m){
            if(y[j])continue;
            for(auto x:l){
                vis[i][x]=0;
            }
        }
        x[i]=0;
    }

    FOR(i,1,m){
        if(y[i])continue;
        y[i]=1;
        VI l;
        int c=0;
        FOR(j,1,n){
            if(x[j])continue;
            if(s[j][i]=='#'&&!vis[j][i]){
                c++;
                vis[j][i]=1;
                l.pb(j);
            }
        }
        dfs(u-c);
        FOR(j,1,n){
            if(x[j])continue;
            for(auto x:l){
                vis[x][i]=0;
            }
        }
        y[i]=0;
    }
}

void solve() {
    cin>>n>>m>>k;

    int tot=0;

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>s[i][j];
            tot+=s[i][j]=='#';
        }
    }

    dfs(tot);

    cout<<ans;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}