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

int l,r;

bool check(int x){
    FOR(i,2,x/i){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

void solve() {
    cin>>l>>r;

    map<int,int>vis,mp;

    FOR(i,l,r){
        int t=i;
        set<int>s;
        while(t!=1){
            int num=0; 
            while(t){
                num+=(t%10)*(t%10);
                t/=10;
            }
            if(s.count(num))break;
            t=num;
            s.insert(t);
            mp[t]=1;
        }
        if(t==1){
            int ans=s.sz;
            if(check(i))ans*=2;
            for(auto x:s){
                if(vis[x]||mp[x])vis[x]=0;
            }
            if(!mp[i]){
                vis[i]=ans;
            }
        }
    }
    bool f=false;
    for(auto [x,y]:vis){
        if(y>0){
            cout<<x<<' '<<y<<endl;
            f=1;
        }
    }

    if(!f){
        cout<<"SAD";
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}