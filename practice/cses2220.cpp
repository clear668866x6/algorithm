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
int num[25],cnt;
int f[20][10][2][2];

int dfs(int u,int prev,bool is0,bool lim){
    if(!u)return 1;
    if(f[u][prev][is0][lim]!=-1)return f[u][prev][is0][lim];

    int res=0;

    FOR(i,0,lim?num[u]:9){
        if(i!=prev){
            if(!i&&is0){
                res+=dfs(u-1,-1,1,lim&(i==num[u]));
            }else{
                res+=dfs(u-1,i,0,lim&(i==num[u]));
            }
        }
    }
    return f[u][prev][is0][lim]=res;
}

int work(int x){
    cnt=0;
    memset(f,-1,sizeof f);
    while(x){
        num[++cnt]=x%10;
        x/=10;
    }
    return dfs(cnt,-1,1,1);
}

void solve() {
    cin>>a>>b;

    cout<<work(b)-work(a-1)<<endl;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}