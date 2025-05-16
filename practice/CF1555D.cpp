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

int n,m;
string s;
int sum[N][8];
//应该得想到满足条件的序列是长什么样子的
//因为这种问题都只有两种方法的，一个是从起点出发；一个是从终点出发

void work(char a,char b,char c,int idx){

    FOR(i,1,n){
        sum[i][idx]=sum[i-1][idx];
        if(i%3==0&&s[i]!=a)sum[i][idx]++;
        if(i%3==1&&s[i]!=b)sum[i][idx]++;
        if(i%3==2&&s[i]!=c)sum[i][idx]++;
    }
}

void solve() {
    cin>>n>>m>>s;

    s=' '+s;

    work('a','b','c',1);
    work('a','c','b',2);
    work('b','a','c',3);
    work('b','c','a',4);
    work('c','a','b',5);
    work('c','b','a',6);

    while(m--){
        int l,r;
        cin>>l>>r;
        int ans=1e18;
        FOR(i,1,6){
            ans=min(ans,sum[r][i]-sum[l-1][i]);
        }
        cout<<ans<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}