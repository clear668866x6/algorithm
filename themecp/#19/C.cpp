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
constexpr int N = 1e3 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
char s[N][N];

void solve() {
    cin>>n;

    FOR(i,1,n){
        FOR(j,1,n){
            cin>>s[i][j];
        }
    }

    vector<vector<int>>g(n+1);
    VI d(n+1,0);

    FOR(i,1,n){
        FOR(j,1,n){
            if(i>=j)continue;
            if(s[i][j]=='1'){
                g[i].emplace_back(j);
                d[j]++;
            }else{
                g[j].emplace_back(i);
                d[i]++;
            }
        }
    }

    queue<int>q;

    FORD(i,1,n){
        if(!d[i]){
            q.push(i);
        }
    }

    while(q.sz){
        int t=q.front();
        q.pop();
        cout<<t<<' ';

        for(auto& j:g[t]){
            if((--d[j])==0){
                q.push(j);
            }
        }
    }
    cout<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}