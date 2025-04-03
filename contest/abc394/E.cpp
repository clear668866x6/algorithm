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
constexpr int N = 1e2 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

char s[N][N];
int n;

void solve() {
    cin>>n;

    FOR(i,1,n){
        FOR(j,1,n)cin>>s[i][j];
    }

    vector<vector<int>>dist(n+1,vector<int>(n+1,1e18));

    queue<PII>q;

    FOR(i,1,n){
        dist[i][i]=0;
        q.push({i,i});//避免重复入列
    }

    FOR(i,1,n){
        FOR(j,1,n){
            if(i!=j&&s[i][j]!='-'){
                q.push({i,j});
                dist[i][j]=1;
            }
        }
    }

    while(q.sz){
        auto [a,b]=q.front();
        q.pop();

        FOR(k,1,n){
            FOR(l,1,n){
                if(s[k][a]==s[b][l]&&s[k][a]!='-'&&dist[k][l]==1e18){
                    dist[k][l]=dist[a][b]+2;
                    q.push({k,l});
                }
            }
        }
    }

    FOR(i,1,n){
        FOR(j,1,n){
            if(dist[i][j]==1e18)dist[i][j]=-1;
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}