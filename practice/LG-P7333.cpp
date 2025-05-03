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
constexpr int N = 6e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int f[N][22];
int a[N],b[N];
//二分+st表

void init(){
    FOR(j,0,20){
        for(int i=1;i+(1<<j)-1<=3*n;i++){
            if(!j)f[i][j]=a[i];
            else f[i][j]=max(f[i][j-1],f[i+(1ll<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r){
    int len=log2(r-l+1);

    return max(f[l][len],f[r-(1ll<<len)+1][len]);
}

int calc(int x,int i){
    int l=0,r=n;

    while(l+1!=r){
        int mid=l+r>>1;
        if(max(query(i-mid,i-1),query(i+1,i+mid))>=x){
            r=mid;
        }else{
            l=mid;
        }
    }
    if(r==n)return -1;
    return r;
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>a[i];
    FOR(i,1,n){
        a[i+2*n]=a[i+n]=a[i];
    }
    init();
    FOR(i,1,n)cin>>b[i];

    FOR(i,1,n){
        cout<<calc(b[i],i+n)<<" ";
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}