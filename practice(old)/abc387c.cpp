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
constexpr int N = 30;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int l,r;
int num[N],cnt;
int f[N][N];

int dfs(int u,int top,bool lim){
    if(!u)return 1;
    if(!lim&&f[u][top]!=-1)return f[u][top];
    int mx=(lim?num[u]:9);
    int ans=0;
    for(int i=0;i<=mx&&i<top;i++){
        ans+=dfs(u-1,(top==10&&i!=0)?i:top,i==mx&&lim);
    }

    if(!lim)f[u][top]=ans;

    return ans;
}

int calc(int x){
    cnt=0;
    while(x){
        num[++cnt]=x%10;
        x/=10;
    }

    return dfs(cnt,10,1);
}

void solve() {
    cin>>l>>r;
    memset(f,-1,sizeof f);
    // cout<<calc(l-1)<<endl;
    
    cout<<calc(r)-calc(l-1)<<endl;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}