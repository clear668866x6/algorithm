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

int n;
int d[N][N];
int p[N];
int sex[N];

void solve() {
    cin>>n;

    FOR(i,1,n){
        FOR(j,1,n){
            if(i!=j)d[i][j]=1e18;
        }
    }

    string s(n+1,0);

    FOR(i,1,n){
        cin>>s[i];
        int k;
        cin>>k;
        while(k--){
            int a,b;
            char c;
            cin>>a>>c>>b;
            d[a][i]=min(d[a][i],b);
        }
    }


    FOR(k,1,n){
        FOR(i,1,n){
            FOR(j,1,n){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    FOR(i,1,n){
        sex[i]=(s[i]=='F');
    }

    FOR(i,1,n){
        FOR(j,1,n){
            if(sex[i]^sex[j]){
                p[i]=max(p[i],d[i][j]);
            }   
        }
    }

    VI female,male;

    int a=1e18,b=1e18;

    FOR(i,1,n){
        if(sex[i]==1)a=min(a,p[i]);
        else b=min(b,p[i]);
    }

    FOR(i,1,n){
        if(sex[i]==1){
            if(a==p[i]){
                female.pb(i);
            }
        }else{
            if(b==p[i]){
                male.pb(i);
            }
        }
    }

    FOR(i,0,female.sz-1)cout<<female[i]<<" \n"[i==female.sz-1];
    FOR(i,0,male.sz-1)cout<<male[i]<<" \n"[i==male.sz-1];

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}