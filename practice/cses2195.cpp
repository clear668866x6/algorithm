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
struct E{
    int x,y;
    bool operator<(const E& t)const{
        if(x==t.x)return y<t.y;
        return x<t.x;
    }
}w[N];
vector<E>hull;

bool convex(E a,E b,E c){
    return (c.x-b.x)*(b.y-a.y)>(c.y-b.y)*(b.x-a.x);
    //yb-ya/xb-xa>yc-yb/xc-xb
}

void add(E a){
    while(hull.sz>1&&convex(hull.end()[-2],hull.back(),a)){
        hull.pop_back();
    }
    hull.pb(a);
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i].x>>w[i].y;

    sort(w+1,w+1+n);

    FOR(i,1,n)add(w[i]);

    reverse(w+1,w+1+n);

    FOR(i,2,n)add(w[i]);

    cout<<hull.sz-1<<endl;

    FOR(i,1,hull.sz-1){
        cout<<hull[i].x<<' '<<hull[i].y<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}