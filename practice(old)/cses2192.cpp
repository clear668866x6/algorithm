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

//判断一个点是否在一个多边形内
/*对要判断的点向任意方向做射线，如果这条射线与多边形的交点是奇数，则表明这个点位于多边形内，
是偶数，则表明这个点位于多边形外。这个方法并不适用于点位于多边形边上的情况。
*/

struct E{
    int x,y;
    E operator+(const E& t)const{
        return {x+t.x,y+t.y};
    }
    E operator-(const E& t)const{
        return {x-t.x,y-t.y};
    }
}w[N],p;

int n,m;

int cross(E a,E b){
    return a.x*b.y-a.y*b.x;
}

int dot(E a,E b){
    return a.x*b.x+a.y*b.y;
}

int sign(int x){
    if(x>0)return 1;
    if(x<0)return -1;
    return 0;
}

bool onseg(E a,E b,E c){
    if(cross(c-a,b-a)!=0)return false;
    if(dot(c-a,b-a)>=0&&dot(b-a,b-a)>=dot(c-a,b-a))return 1;
    return 0;
}

bool get_line_intersaction(E a,E b,E c,E d){
    int f1=sign(cross(a-c,d-c))*sign(cross(b-c,d-c));
    int f2=sign(cross(c-a,b-a))*sign(cross(d-a,b-a));
    if(f1<0&&f2<0)return 1;
    if(f1>0||f2>0)return 0;
    if(onseg(a,b,c))return 1;
    if(onseg(a,b,d))return 1;
    if(onseg(c,d,a))return 1;
    if(onseg(c,d,b))return 1;
    return 0;
}

void work(E x){
    FOR(i,2,n-1){
        if(onseg(w[i-1],w[i],x)){
            cout<<"BOUNDARY"<<endl;
            RE;
        }
    }
    if(onseg(w[n],w[1],x)){
        cout<<"BOUNDARY"<<endl;
        RE;
    }
    E y=x+E{1,(int)2e9};//射线

    int cnt=0;

    FOR(i,2,n){
        if(get_line_intersaction(x,y,w[i-1],w[i]))cnt++;
    }
    if(get_line_intersaction(x,y,w[n],w[1]))cnt++;

    if(cnt&1){
        cout<<"INSIDE"<<endl;
    }else{
        cout<<"OUTSIDE"<<endl;
    }
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>w[i].x>>w[i].y;

    FOR(i,1,m){
        cin>>p.x>>p.y;
        work(p);
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}