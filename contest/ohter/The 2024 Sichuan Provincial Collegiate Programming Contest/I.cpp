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

int n,l,h;
int x[N],y[N],a[N],b[N];
set<int>sx,sy;
//很好的填矩形的问题（矩形还不能相交的）

void solve() {
    cin>>n>>l>>h;

    sx.insert(0),sy.insert(0);

    FOR(i,1,n)cin>>a[i]>>b[i],x[i]=y[i]=-1;

    FOR(i,1,n){
        for(auto cx:sx){
            for(auto cy:sy){
                if(a[i]+cx>l||b[i]+cy>h)continue;

                bool f=true;

                FOR(j,1,i-1){
                    //判断两个矩形是否相交（要么在新的矩形的左边，要么在右边），新的矩形是 [vx,vx+a[i]] [vy,vy+b[i]]，旧的矩形是 [x[j],x[j]+a[j]]
                    if(!(x[j]==-1||a[j]+x[j]<=cx||b[j]+y[j]<=cy||cx+a[i]<=x[j]||cy+b[i]<=y[j])){
                        f=0;
                        break;
                    }
                }
                if(f){
                    x[i]=cx,y[i]=cy;
                    sx.insert(cx+a[i]);
                    sy.insert(cy+b[i]);
                    break;
                }
            }
            if(x[i]!=-1)break;
        }
        if(x[i]==-1)cout<<-1<<endl;
        else cout<<x[i]<<' '<<y[i]<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}