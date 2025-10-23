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
constexpr int N = 500 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

char s[N][N];
int n,m;

PII get(char x){
    if(x=='U')return {-1,0};
    if(x=='D')return {1,0};
    if(x=='L')return {0,-1};
    return {0,1};
}

void solve() {
    cin>>n>>m;

    bool f=false;

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>s[i][j];
        }
    }

    FOR(i,1,n){
        FOR(j,1,m){
            if(s[i][j]=='.'){
                f=1;
                if(!(i==1&&j==m)){
                    No;
                    RE;
                }
            }
        }
    }

    if(!f){
        No;
        RE;
    }

    int ans=0;

    FOR(i,1,n){
        FOR(j,1,m){
            int cnt=0;
            if(s[i][j]!='.'&&s[i][j]!='C'){
                PII t=get(s[i][j]);
                int x=i+t.fi,y=j+t.se;
                if(x<1||y<1||x>n||y>m||s[x][y]!='C'){
                    No;
                    RE;
                }
            }else if(s[i][j]=='C'){
                cnt++;
                if(s[i][j-1]=='R')cnt++;
                if(s[i][j+1]=='L')cnt++;
                if(s[i-1][j]=='D')cnt++;
                if(s[i+1][j]=='U')cnt++;
            }
            if(cnt>=3)ans+=3;
        }
    }

    if(ans!=n*m-1){
        No;
    }else{
        Yes;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}