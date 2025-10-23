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

/*
边界的格点数
把每条边当作左开右闭的区间避免重复，一条左开右闭的线段 AB上的格点数为 gcd(Bx−Ax,By−Ay)。
*/

int n;
struct E{
    int x,y;
    E operator-(const E& t)const{
        return {x-t.x,y-t.y};
    }
}w[N];

int cross(E a,E b){
    return a.x*b.y-a.y*b.x;
}

int area(){
    int ans=0;

    FOR(i,2,n-1){
        ans+=cross(w[i]-w[1],w[i+1]-w[i]);
    }
    return abs(ans);
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i].x>>w[i].y;

    int cnt=0;

    FOR(i,2,n){
        cnt+=__gcd(abs(w[i].x-w[i-1].x),abs(w[i].y-w[i-1].y));
    }
    cnt+=__gcd(abs(w[n].x-w[1].x),abs(w[n].y-w[1].y));

    int a=(area()-cnt+2)/2;

    cout<<a<<' '<<cnt<<endl;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}