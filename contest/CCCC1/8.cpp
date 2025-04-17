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
constexpr int N = 50 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m,d;
int w[N][N];

void solve() {
    cin>>n>>m>>d;

    FOR(i,1,n){
        FOR(j,1,m){
            cin>>w[i][j];
        }
    }

    int tot=0,ans=0,ansl=0,ansr=0;

    FOR(i,1,n){
        FOR(j,1,m){
            if(w[i][j]==0){
                int pt=0;
                int r=j;
                while(r<=m&&(w[i][r]<=0||w[i][r]<d)){
                    if(w[i][r]<0){
                        pt++;
                    }
                    r++;
                }
                r=j;
                while(r>=1&&(w[i][r]<=0||w[i][r]<d)){
                    if(w[i][r]<0){
                        pt++;
                    }
                    r--;
                }
                int l=i;
                while(l<=n&&(w[l][j]<=0||w[l][j]<d)){
                    if(w[l][j]<0){
                        pt++;
                    }
                    l++;
                }
                l=i;
                while(l>=1&&(w[l][j]<=0||w[l][j]<d)){
                    if(w[l][j]<0){
                        pt++;
                    }
                    l--;
                }
                if(pt>=3){
                    tot++;
                    if(pt>ans){
                        ans=pt;
                        ansl=i,ansr=j;
                    }
                }
            }
        }
    }

    cout<<tot<<endl;
    cout<<(ansl-1)<<' '<<(ansr-1)<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}