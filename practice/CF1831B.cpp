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

int n,a[N],b[N];

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>a[i];
    FOR(i,1,n)cin>>b[i];

    VI acnt(n*2+1,0),bcnt(n*2+1,0);

    int sum=1;

    FOR(i,1,n){
        if(a[i]==a[i-1])sum++;
        else{
            acnt[a[i-1]]=max(acnt[a[i-1]],sum);
            sum=1;
        }
    }
    acnt[a[n]]=max(acnt[a[n]],sum);
    
    sum=1;

    FOR(i,1,n){
        if(b[i]==b[i-1])sum++;
        else{
            bcnt[b[i-1]]=max(bcnt[b[i-1]],sum);
            sum=1;
        }
    }
    bcnt[b[n]]=max(bcnt[b[n]],sum);

    int ans=0;

    FOR(i,1,n){
        ans=max({ans,acnt[a[i]]+bcnt[a[i]],acnt[b[i]]+bcnt[b[i]]});
    }
    cout<<ans<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}