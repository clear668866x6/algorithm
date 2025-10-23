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

int s;
int n;
struct E{
    int pre,val,ne;
}w[N];

void solve() {
    cin>>s>>n;

    map<int,int>pos;

    FOR(i,1,n){
        int a,b,c;
        cin>>a>>b>>c;
        w[i]={a,b,c};
        pos[a]=i;
    }

    int id=pos[s];

    vector<E>v;

    while(id!=0){
        v.pb(w[id]);
        id=pos[w[id].ne];
    }

    int l=0,r=v.sz-1;

    vector<E>res;

    while(l<r){
        res.pb({v[r].pre,v[r].val,v[l].pre});
        res.pb({v[l].pre,v[l].val,v[r-1].pre});
        l++,r--;
    }

    if((v.sz)&1){
        res.pb({v[r].pre,v[r].val,-1});
    }

    int t=0;

    for(auto [x,y,z]:res){
        if(t==v.sz-1){
            printf("%05lld %lld -1\n",x,y);
        }else{
            printf("%05lld %lld %05lld\n",x,y,z);
        }
        t++;
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}