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
constexpr int N = 40 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int w[N][N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

void solve() {
    cin>>n;

    w[(n+1)/2][(n+1)/2]=10000;

    int x=1,y=1,idx=0,cnt=1;

    while(1){
        if(x==(n+1)/2&&y==(n+1)/2){
            break;
        }

        w[x][y]=cnt;
        cnt++;
        int a=x+dx[idx],b=y+dy[idx];
        if(a<1||b<1||a>n||b>n||w[a][b]){
            idx=(idx+1)%4;
        }
        x+=dx[idx],y+=dy[idx];
    }

    FOR(i,1,n){
        FOR(j,1,n){
            if(w[i][j]==10000){
                cout<<"T ";
            }else{
                cout<<w[i][j]<<' ';
            }
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