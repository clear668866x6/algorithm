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
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

void solve() {
    cin>>n;

    FOR(i,1,n){
        FOR(j,1,n){
            cin>>s[i][j];
        }
    }

    FOR(i,1,n){
        FOR(j,1,n){
            FOR(k,0,7){
                int a=i,b=j;
                int cnt=(s[i][j]=='#');
                int t=(s[i][j]=='.');
                FOR(p,1,5){//以后有限定次数直接限定了
                    a+=dx[k];
                    b+=dy[k];
                    if(a>=1&&b>=1&&a<=n&&b<=n){
                        if(s[a][b]=='#')cnt++;
                        else t++,cnt++;
                    }
                }
                if(t<=2&&cnt>=6){
                    Yes;
                    RE;
                }
            }
        }
    }

    No;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}