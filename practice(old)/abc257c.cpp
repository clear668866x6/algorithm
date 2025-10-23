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
constexpr int mod = 1e9 + 7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
string s;
int w[N];
int a[N],ca,b[N],cb;

void solve() {
    cin>>n>>s;

    s=' '+s;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,n){
        if(s[i]=='1'){
            a[++ca]=w[i];
        }else{
            b[++cb]=w[i];
        }
    }

    if(!ca||!cb){
        cout<<ca+cb<<endl;
        RE;
    }

    sort(a+1,a+1+ca),sort(b+1,b+1+cb);

    int ans=0;
    
    FOR(i,1,n){
        int t1=lower_bound(b+1,b+1+cb,w[i])-b;
        int t2=lower_bound(a+1,a+1+ca,w[i])-a;
        int t3=lower_bound(b+1,b+1+cb,w[i]+1)-b;
        int t4=lower_bound(a+1,a+1+ca,w[i]+1)-a;
        ans=max(ans,ca-t2+1+max<int>(0,t1-1));
        ans=max(ans,ca-t4+1+max<int>(0,t3-1));
    }

    cout<<ans;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}