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

int k;
VI g[20];
map<PII,int>mp,cnt;

void work(){
    FOR(i,0,k-1){
        FOR(j,0,g[i].sz-1){
            int t=g[i][j],d1=mp[{i+1,j*2}],d2=mp[{i+1,j*2+1}];
            if(t>=d1&&cnt[{i,j}]>=d2){
                cnt[{i+1,j*2}]=t;
                cnt[{i+1,j*2+1}]=cnt[{i,j}];
            }else if(t>=d2&&cnt[{i,j}]>=d1){
                cnt[{i+1,j*2+1}]=t;
                cnt[{i+1,j*2}]=cnt[{i,j}];
            }else{
                cout<<"No Solution";
                exit(0);
            }
        }
    }

    FOR(i,0,g[k-1].sz-1){
        cout<<g[k-1][i]<<' '<<cnt[{k-1,i}]<<" \n"[i==g[k-1].sz-1];
    }

}

void solve() {
    cin>>k;

    FORD(i,0,k-1){
        FOR(j,0,(1<<i)-1){
            int x;
            cin>>x;
            g[i].emplace_back(x);
            if(i==k-1){
                mp[{i,j}]=x;
            }else{
                mp[{i,j}]=max(mp[{i+1,j*2}],mp[{i+1,j*2+1}]);
                mp[{i,j}]=max(mp[{i,j}],g[i][j]);
            }
        }
    }

    int x;
    cin>>x;

    cnt[{0,0}]=x;
    if(x<mp[0][0]){
        cout<<"No Solution";
    }else{
        work();
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}