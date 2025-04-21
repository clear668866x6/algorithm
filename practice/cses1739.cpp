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
constexpr int N = 1000 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int tr[N][N];
int n,m;
char s[N][N];
int w[N][N];

void add(int x,int y,int c){
    for(int i=x;i<N;i+=lowbit(i)){
        for(int j=y;j<N;j+=lowbit(j)){
            tr[i][j]+=c;
        }
    }
}

int query(int x,int y){
    int res=0;
    for(int i=x;i;i-=lowbit(i)){
        for(int j=y;j;j-=lowbit(j)){
            res+=tr[i][j];
        }
    }
    return res;
}

void solve() {
    cin>>n>>m;

    FOR(i,1,n){
        FOR(j,1,n){
            cin>>s[i][j];
            if(s[i][j]=='*')w[i][j]=1,add(i,j,1);
        }
    }

    while(m--){
        int op,x,y;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            int k=(w[x][y]^1)-w[x][y];
            w[x][y]^=1;
            add(x,y,k);
        }else{
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<(query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1))<<endl;
        }
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}