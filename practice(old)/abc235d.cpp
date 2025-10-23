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
constexpr int N = 2e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int a,n;
bool vis[N];
struct E{
    int x,step;
    bool operator<(const E& t)const{
        return step>t.step;
    }
};

void solve() {
    cin>>a>>n;

    priority_queue<E>q;

    q.push({1,0});
    vis[1]=1;

    while(q.sz){
        auto [x,step]=q.top();
        q.pop();

        if(x==n){
            cout<<step;
            RE;
        }
        bool f=false;
        if((x*a<=1e6&&!vis[x*a])){
            vis[x*a]=1;
            q.push({x*a,step+1});

        }
        string p=to_string(x);
        if(p[p.sz-1]=='0'&&p.sz>1)continue;
        p=' '+p;
        swap(p[0],p[p.sz-1]);
        p.pop_back();
        int m=0;
        for(auto t:p){
            m=m*10+(t-'0');
        }
        if(!(vis[m])){
            vis[m]=1;
            q.push({m,step+1});
        }
    }
    cout<<-1;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}