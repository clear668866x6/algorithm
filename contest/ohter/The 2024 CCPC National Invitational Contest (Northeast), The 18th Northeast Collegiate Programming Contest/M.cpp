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
constexpr int N = 300 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,ans;
map<PII,int>mp;
int x[N],y[N];

int dis(int a,int b,int c,int d){
    return (a-c)*(a-c)+(b-d)*(b-d);
}

bool check(int a,int b,int c){
    return (y[b]-y[a])*(x[c]-x[a])>(y[c]-y[a])*(x[b]-x[a]);
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>x[i]>>y[i],mp[{x[i],y[i]}]++;

    FOR(c,1,n){
        FOR(d,1,n){
            if(c==d)continue;
            int a1=0,a2=0,a3=0,a4=0;
            FOR(e,1,n){
                if(c==e||d==e)continue;
                if((y[d]-y[c])*(x[d]-x[e])==(y[d]-y[e])*(x[d]-x[c]))continue;
                if(dis(x[d],y[d],x[e],y[e])==dis(x[c],y[c],x[e],y[e])){
                    if(check(d,c,e))a1++;
                    else a2++;
                }
            }
            FOR(a,1,n){
                if(a==c||a==d)continue;
                if((y[d]-y[c])*(y[d]-y[a])+(x[d]-x[c])*(x[d]-x[a])!=0)continue;
                int tx=x[a]+x[c];
                int ty=y[a]+y[c];
                if(check(d,c,a))a3+=mp[{tx-x[d],ty-y[d]}];
                else a4+=mp[{tx-x[d],ty-y[d]}];
            }
            ans+=a1*a4+a2*a3;
        }
    }
    cout<<ans/2;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}