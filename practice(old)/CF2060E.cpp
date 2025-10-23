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

int n,m1,m2;
int p1[N],p2[N];
int a[N],b[N];

int find1(int x){
    if(x!=p1[x])p1[x]=find1(p1[x]);
    return p1[x];
}

int find2(int x){
    if(x!=p2[x])p2[x]=find2(p2[x]);
    return p2[x];
}

void solve() {
    cin>>n>>m1>>m2;

    FOR(i,1,n)p1[i]=p2[i]=i;
    
    FOR(i,1,m1)cin>>a[i]>>b[i];
    
    int ans=0,c1=0,c2=0,c=0;

    FOR(i,1,m2){
        int a,b;
        cin>>a>>b;
        if(find1(a)!=find1(b)){
            p1[find1(a)]=find1(b);
        }
    }

    FOR(i,1,m1){
        if(find1(a[i])==find1(b[i])){
            p2[find2(a[i])]=find2(b[i]);
        }else{
            ans++;
        }
    }

    FOR(i,1,n){
        if(i==p1[i])c1++;
        if(i==p2[i])c2++;
    }

    cout<<(c2-c1+ans)<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}