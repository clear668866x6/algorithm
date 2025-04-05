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


namespace duidingdui{
    multiset<int>l,r;

    void balance(){
        while(l.sz>r.sz+1){
            r.insert(*l.rbegin());
            l.erase(prev(l.end()));
        }

        while(l.sz<r.sz){
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    }

    void add(int x){
        if(!l.sz||*l.rbegin()>=x){
            l.insert(x);
        }else{
            r.insert(x);
        }
        balance();
    }

    void remo(int x){
        if(l.count(x)){
            l.erase(l.find(x));
        }else{
            r.erase(r.find(x));
        }
        balance();
    }

    int mid(){
        return *l.rbegin();
    }
}

using namespace duidingdui;

int n,k,w[N];

void solve() {
    cin>>n>>k;

    FOR(i,1,n)cin>>w[i];

    FOR(i,1,k){
        add(w[i]);
    }

    cout<<mid()<<' ';

    FOR(i,k+1,n){
        remo(w[i-k]);
        add(w[i]);
        cout<<mid()<<' ';
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}