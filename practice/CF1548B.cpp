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

int n,w[N],b[N];
int tr[N][22];
//想到：差的形式
//卡在：最后答案是最长的gcd>1的区间
void init(){
    FOR(j,0,20){
        for(int i=1;i+(1<<j)-1<=n;i++){
            if(!j)tr[i][j]=b[i];
            else tr[i][j]=__gcd(tr[i][j-1],tr[i+(1<<j-1)][j-1]);
        }
    }
}

int query(int l,int r){
    int len=__lg(r-l+1);
    return __gcd(tr[l][len],tr[r-(1<<len)+1][len]);
}

bool check(int x){
    FOR(i,1,n-x){
        if(query(i,i+x)>1){
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n-1){
        b[i]=abs(w[i+1]-w[i]);
        // cout<<b[i]<<" ";
    }
    // cout<<endl;
    n--;

    init();

    int l=-1,r=n+2;

    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }

    cout<<r+1<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}