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

int n,q;

int dfs1(int x,int y,int ans,int dep){
    if(x==1&&y==1)return ans+1;
    int t1=(1ll<<(dep-1));
    int t2=(1ll<<((dep-1)*2));

    if(x<=t1&&y<=t1)return dfs1(x,y,ans,dep-1);
    else if(x>t1&&y>t1)return dfs1(x-t1,y-t1,ans+t2,dep-1);
    else if(x>t1&&y<=t1)return dfs1(x-t1,y,ans+t2*2,dep-1);
    else return dfs1(x,y-t1,ans+t2*3,dep-1);
}

void dfs2(int x,int y,int ans,int dep){
    if(ans==1){
        cout<<x+1<<' '<<y+1<<endl;
        RE;
    }

    int t1=(1ll<<(dep-1));
    int t2=(1ll<<((dep-1)*2));

    if(ans>t2*3)dfs2(x,y+t1,ans-t2*3,dep-1);
    else if(ans>t2*2)dfs2(x+t1,y,ans-t2*2,dep-1);
    else if(ans>t2)dfs2(x+t1,y+t1,ans-t2,dep-1);
    else dfs2(x,y,ans,dep-1);
}

void solve() {
    cin>>n>>q;

    while(q--){
        string s;
        cin>>s;
        if(s=="->"){
            int a,b;
            cin>>a>>b;
            cout<<dfs1(a,b,0,n)<<endl;
        }else{
            int x;
            cin>>x;
            dfs2(0,0,x,n);
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