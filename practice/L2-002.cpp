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
constexpr int N = 1e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

struct E{
    int a,b,c;
}w[N];

int head;
int n,ne[N];
bool vis[N];

void dfs(vector<E> v){
    FOR(i,0,v.sz-1){
        printf("%05lld %lld",v[i].a,v[i].b);
        if(i+1<v.sz){
            printf(" %05lld\n",v[i+1].a);
        }else{
            printf(" -1\n");
        }
    }
}

void solve() {
    cin>>head>>n;

    int a,b,c;

    while(n--){
        cin>>a>>b>>c;
        w[a]={a,b,c};
        ne[a]=c;
    }

    vector<E>v1,v2;

    for(int i=head;i!=-1;i=ne[i]){
        if(!vis[abs(w[i].b)]){
            vis[abs(w[i].b)]=1;
            v1.pb(w[i]);
        }else{
            v2.pb(w[i]);
        }
    }

    dfs(v1);
    dfs(v2);


}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}