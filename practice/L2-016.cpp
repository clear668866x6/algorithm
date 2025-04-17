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

int n,q,p[N];
struct E{
    int fa;
    int ma;
    char sex;
}w[N];

int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}

void uni(int a,int b){
    if(b==-1)return;
    int pa=find(a),pb=find(b);
    if(pa!=pb){
        p[pa]=pb;
    }
}

bool dfs(int a,int b,int dep){
    if(a==-1||b==-1)return true;
    if(dep>5)return true;

    if(a==b)return false;

    return dfs(w[a].fa,w[b].fa,dep+1)&&dfs(w[a].ma,w[b].ma,dep+1)&&
    dfs(w[a].fa,w[b].ma,dep+1)&&dfs(w[a].ma,w[b].fa,dep+1);

}

void solve() {
    cin>>n;

    FOR(i,1,1e5)p[i]=i,w[i].fa=w[i].ma=-1;

    FOR(i,1,n){
        int id;
        cin>>id;
        cin>>w[id].sex>>w[id].fa>>w[id].ma;
        uni(id,w[id].fa);
        uni(id,w[id].ma);
        if(w[id].fa!=-1){
            w[w[id].fa].sex='M';
        }
        if(w[id].ma!=-1){
            w[w[id].ma].sex='F';
        }
    }

    cin>>q;

    while(q--){
        int a,b;
        cin>>a>>b;
        if(w[a].sex==w[b].sex){
            cout<<"Never Mind"<<endl;
        }else if(dfs(a,b,1)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}