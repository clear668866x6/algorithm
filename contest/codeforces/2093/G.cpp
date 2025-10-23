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
int w[N];
//https://www.luogu.com.cn/article/g2pikvbh
//01字典树
struct Tire{
    int tr[N*30][2],pos[N*30],idx;

    void clear(){
        FOR(i,1,idx)tr[i][0]=tr[i][1]=pos[i]=0;
        idx=1;
    }

    void insert(int x,int y){
        int p=1;
        FORD(i,0,30){
            int t=x>>i&1;
            if(!tr[p][t])tr[p][t]=++idx;
            p=tr[p][t];
            pos[p]=max(pos[p],y);
        }
    }

    int query(int x){
        int p=1,ans=0,mx=-1;
        FORD(i,0,30){
            int t=x>>i&1;
            if(tr[p][t^1]){
                if((ans+(1<<i))>=m)mx=max(mx,pos[tr[p][t^1]]),p=tr[p][t];
                else p=tr[p][t^1],ans+=(1<<i);
            }else if(tr[p][t])p=tr[p][t];
            else break;
        }
        return mx;
    }
}t;

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i];

    if(!m){
        cout<<1<<endl;
        RE;
    }

    int ans=1e18;
    t.clear();

    FOR(i,1,n){
        t.insert(w[i],i);
        int res=t.query(w[i]);
        if(res!=-1){
            ans=min(ans,i-res+1);
        }
    }
    if(ans==1e18)cout<<-1<<endl;
    else cout<<ans<<endl;
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}