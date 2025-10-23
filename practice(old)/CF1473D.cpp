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

int n,w[N],q;
int pre[N];
int tr1[N][22],tr2[N][22];

void init(){
    FOR(j,0,22){
        for(int i=1;i+(1<<j)-1<=n;i++){
            if(!j){
                tr1[i][j]=tr2[i][j]=pre[i];
            }else{
                tr1[i][j]=max(tr1[i][j-1],tr1[i+(1<<j-1)][j-1]);
                tr2[i][j]=min(tr2[i][j-1],tr2[i+(1<<j-1)][j-1]);
            }
        }
    }
}

int query1(int l,int r){
    int len=__lg(r-l+1);
    return max(tr1[l][len],tr1[r-(1<<len)+1][len]);
}

int query2(int l,int r){
    int len=__lg(r-l+1);
    return min(tr2[l][len],tr2[r-(1<<len)+1][len]);
}

void solve() {
    string s;
    cin>>n>>q>>s;
    
    FOR(i,1,n){
        if(s[i-1]=='+')pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1]-1;
    }

    init();

    while(q--){
        int l,r;
        cin>>l>>r;

        int l1=1,r1=l-1;
        int l2=r+1,r2=n;
        int mn=1e18,mx=-1e18;
        if(l1<=r1){
            mn=min(mn,query2(l1,r1));
            mx=max(mx,query1(l1,r1));
        }

        if(l2<=r2){
            mn=min(mn,query2(l2,r2)-pre[r]+pre[l-1]);
            mx=max(mx,query1(l2,r2)-pre[r]+pre[l-1]);
        }

        if(mn==1e18)mn=0;
        if(mx==-1e18)mx=0;
        if(mn<=0&&mx>=0){
            cout<<(mx-mn+1)<<endl;
        }else{
            cout<<(mx-mn+2)<<endl;
        }
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}