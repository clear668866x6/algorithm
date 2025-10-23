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

int tr[N];
int n;
int w[N];
//类似约瑟夫环的树状数组优化，用二分+树状数组

void add(int x,int c){
    for(int i=x;i<N;i+=lowbit(i))tr[i]+=c;
}

int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}

int getans(int u){
    int l=0,r=n+1;

    while(l+1!=r){
        int mid=l+r>>1;
        if(query(mid)>=u)r=mid;
        else l=mid;
    }
    return r;
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n){
        add(i,1);
    }

    FOR(i,1,n){
        int x;
        cin>>x;
        int id=getans(x);
        cout<<w[id]<<' ';
        add(id,-1);
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}