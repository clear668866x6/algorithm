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

int w[10];
int n=5;

void solve() {
    int s=0;
    FOR(i,1,n)cin>>w[i],s+=w[i];

    int ans=0;

    //5 x
    int t=min(s/2,w[5]);
    w[5]-=t;
    s-=t*2;
    ans+=t;

    //4 2
    t=min({w[4],w[2],s/2});
    w[4]-=t,w[2]-=t;
    s-=t*2;
    ans+=t;

    //3 3
    t=min(w[3]/2,s/2);
    w[3]-=t*2;
    s-=t*2;
    ans+=t;

    //3 2 1
    t=min({w[3],w[2],s/3});
    w[2]-=t,w[3]-=t;
    s-=3*t;
    ans+=t;

    //4 1 1
    t=min({w[4],s/3});
    w[4]-=t;
    s-=t*3;
    ans+=t;

    //2 2 2
    t=min(w[2]/3,s/3);
    w[2]-=t*3;
    s-=t*3;
    ans+=t;

    //2 2 1 1
    t=min(w[2]/2,s/4);
    w[2]-=t*2;
    s-=t*4;
    ans+=t;

    //3 1 1 1
    t=min(w[3],s/4);
    w[3]-=t;
    s-=t*4;
    ans+=t;

    //2 1 1 1 1
    t=min(w[2],s/5);
    w[2]-=t;
    s-=t*5;
    ans+=t;

    cout<<(ans+s/6)<<endl;
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}