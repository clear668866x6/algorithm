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

球要被整个矩形包围的充要条件是 球心与矩形的每条边的距离大于等于r，因此可以把矩形的边都相应缩小r（
注意特判，2*r不能大于矩形的长和宽）

题意就转化为球心能否过变化后的矩形区域，等价于球心的运动轨迹是否和四条边有交点
*/
double x,y,r,vx,vy;
double lx,ly,rx,ry;

void solve() {
    cin>>x>>y>>r>>vx>>vy;
    cin>>lx>>ly>>rx>>ry;

    if(rx-lx<2*r||ry-ly<2*r){
        No;
        RE;
    }

    lx+=r,ly+=r,rx-=r,ry-=r;

    if(vx!=0){
        double t=(double)(rx-x)/vx;
        if(t>=0){
            if(y+t*vy<=ry&&y+t*vy>=ly){
                Yes;
                RE;
            }
        }
        t=(double)(lx-x)/vx;
        if(t>=0){
            if(y+t*vy<=ry&&y+t*vy>=ly){
                Yes;
                RE;
            }
        }
    }

    if(vy!=0){
        double t=(double)(ry-y)/vy;
        if(t>=0){
            if(x+t*vx<=rx&&x+t*vx>=lx){
                Yes;
                RE;
            }
        }
        t=(double)(ly-y)/vy;
        if(t>=0){
            if(x+t*vx<=rx&&x+t*vx>=lx){
                Yes;
                RE;
            }
        }
    }

    if(!vx&&!vy){
        if(x>=lx&&x<=rx&&y>=ly&&y<=ry){
            Yes;
            RE;
        }
    }
    No;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}