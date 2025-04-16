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

int n;
double V;
struct E{
    double v;
    double w;
    double tot;
    bool operator<(const E& t)const{
        if(w==t.w)return v>t.v;
        return w>t.w;
    }
}w[N];

void solve() {
    cin>>n>>V;

    FOR(i,1,n)cin>>w[i].v;

    FOR(i,1,n){
        double x;
        cin>>x;
        w[i].w=x/w[i].v;
        w[i].tot=x;
    }

    sort(w+1,w+1+n);

    double ans=0;

    FOR(i,1,n){
        if(V>=w[i].v){
            V-=w[i].v;
            ans+=w[i].tot;
        }else{
            ans+=(w[i].w*V);
            break;
        }
    }

    printf("%.2lf",ans);

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}