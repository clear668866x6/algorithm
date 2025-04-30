#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define double long double
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
constexpr double eps= 0;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

struct E{
    int x,y;
}w[3];

int operator&(E a,E b){
    return a.x*b.y-a.y*b.x;
}

void solve() {
    cin>>w[0].x>>w[0].y>>w[1].x>>w[1].y>>w[2].x>>w[2].y;

    E v1={w[1].x-w[0].x,w[1].y-w[0].y};
    E v2={w[2].x-w[0].x,w[2].y-w[0].y};


    int fi=v1&v2;

    if(fi>0){
        cout<<"LEFT"<<endl;
    }else if(fi==0){
        cout<<"TOUCH"<<endl;
    }else{
        cout<<"RIGHT"<<endl;
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}