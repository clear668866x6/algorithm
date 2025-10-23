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

int n,m;
int w[N];

void solve() {
    cin>>n>>m;

    int tot=0;

    VI v(n+1,0);

    FOR(i,1,n){
        cin>>w[i];
        int x=w[i];
        bool f=false;
        while(x){
            if(!f&&(x%10==0)){
                v[i]++;
            }
            tot++;
            if(x%10!=0)f=1;
            x/=10;
        }
    }

    sort(v.begin()+1,v.end(),greater());

    int ans=0;

    int t=0;//0 A  1 S

    FOR(i,1,n){
        if(!v[i])break;
        if(t){
            t^=1;
        }else{
            tot-=v[i];
            t^=1;
        }
    }

    m++;

    if(tot<m){
        cout<<"Anna"<<endl;
    }else{
        cout<<"Sasha"<<endl;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}