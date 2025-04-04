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
constexpr int N = 5e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int f[N][30];
int k;
string a,b;
int na,nb;

int& get(int x,int y){
    return f[x][x-y+22];
}

void solve() {
    cin>>k>>a>>b;

    int n1=a.sz,n2=b.sz;

    a=' '+a,b=' '+b;

    if(abs(n1-n2)>k){
        No;
        RE;
    }

    memset(f,0x3f,sizeof f);

    FOR(i,0,k){
        get(i,0)=get(0,i)=i;
    }

    FOR(i,1,n1){
        FOR(j,max<int>(1,i-k),min<int>(n2,i+k)){
            get(i,j)=min({get(i,j),get(i-1,j)+1,get(i,j-1)+1,get(i-1,j-1)+(a[i]!=b[j])});
        }
    }

    if(get(n1,n2)<=k){
        Yes;
    }else{
        No;
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}