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

int n,k,p;
VI g[N];
int din[N];
bool vis[N];

void solve() {
    cin>>n>>k>>p;

    queue<PII>q;

    FOR(i,1,p){
        int x;
        cin>>x;
        vis[x]=1;
        q.push({x,0});
    }

    int m;
    cin>>m;

    while(m--){
        int i,k;
        cin>>i>>k;
        while(k--){
            int x;
            cin>>x;
            g[x].emplace_back(i);
            din[i]++;
        }
    }

    while(q.sz){
        auto [x,day]=q.front();
        q.pop();

        if(!vis[x])continue;

        if(x==k){
            cout<<day<<endl;
            RE;
        }

        for(auto& j:g[x]){
            --din[j];
            if(!din[j]){
                q.push({j,day+1});
                vis[j]=1;
            }
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