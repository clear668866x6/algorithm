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

int n,m;
struct E{
    VI a;
    int id;
    bool operator<(const E& t)const{
        return a.sz<t.a.sz;
    }
}w[N];
int ans[N],cnt[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        w[i].a.clear();
    }

    FOR(i,1,n)ans[i]=cnt[i]=0;


    unordered_map<int,int>mp;

    FOR(i,1,m){
        int t,x;
        cin>>t;
        w[i].id=i;
        while(t--){
            cin>>x;
            w[i].a.emplace_back(x);
            mp[x]++;
        }
    }

    sort(w+1,w+1+m);

    FOR(i,1,m){
        int mnidx=-1,mn=1e9;
        for(auto x:w[i].a){
            if(cnt[x]<(m+1)/2&&mp[x]<mn){
                mn=mp[x];
                mnidx=x;
            }
        }
        if(mnidx==-1){
            NO;
            RE;
        }
        cnt[mnidx]++;
        ans[w[i].id]=mnidx;
    }

    YES;
    FOR(i,1,m)cout<<ans[i]<<" \n"[i==m];

}

signed main() {
    int Task = 1;
    for (cin>>Task; Task; Task--) {
        solve();
    }
    return 0;
}