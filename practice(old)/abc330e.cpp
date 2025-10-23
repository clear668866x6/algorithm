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
constexpr int N = 4e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,q;
int w[N];
set<int>s;
map<int,int>mp;

void del(int x){
    if(mp[x]==1)s.insert(x);
    mp[x]--;
}

void add(int x){
    if(!mp[x]){
        s.erase(s.find(x));
    }
    mp[x]++;
}

void solve() {
    cin>>n>>q;

    FOR(i,1,n)cin>>w[i],s.insert(i);
    s.insert(0);
    s.insert(n+1);
    FOR(i,1,n){
        if(w[i]>n+1)w[i]=n+1;
        add(w[i]);
    }

    while(q--){
        int i,x;
        cin>>i>>x;
        if(x>n)x=n+1;
        del(w[i]);
        add(x);
        cout<<(*s.begin())<<endl;
        w[i]=x;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}