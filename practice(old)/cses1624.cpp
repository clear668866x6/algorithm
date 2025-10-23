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

char s[12][12];
int n=8,ans;
int a[12],b[12],c[25],d[25];

void dfs(int x,int y,int sp){
    if(sp>n)RE;
    if(y==n)y=0,x++;

    if(x==n){
        if(sp==n){
            ans++;
        }
        RE;
    }
    
    dfs(x,y+1,sp);

    if(!a[x]&&!b[y]&&!c[x+y]&&!d[x-y+n]&&s[x][y]=='.'){
        a[x]=b[y]=c[x+y]=d[x-y+n]=1;
        dfs(x,y+1,sp+1);
        a[x]=b[y]=c[x+y]=d[x-y+n]=0;
    }
}

void solve() {
    FOR(i,0,n-1){
        FOR(j,0,n-1){
            cin>>s[i][j];
        }
    }

    dfs(0,0,0);

    cout<<ans;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}