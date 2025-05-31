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

int n,w[N];

void solve() {
    cin>>n;

    map<int,int>mp;

    FOR(i,1,n)cin>>w[i],mp[w[i]]++;

    bool f=false;
    int id=0,tx=0;
    sort(w+1,w+1+n);

    for(auto [x,y]:mp){
        if(y>1){
            f=1;
            tx=x;
        }
    }

    if(!f){
        int mx=1e18;
        FOR(i,2,n){
            if(w[i]-w[i-1]<=mx){
                mx=w[i]-w[i-1];
                id=i;
            }
        }

        cout<<w[id-1]<<' ';
        FOR(i,id+1,n){
            cout<<w[i]<<' ';
        }
        FOR(i,1,id-2)cout<<w[i]<<' ';
        cout<<w[id]<<endl;

    }else{
        FOR(i,1,n){
            if(w[i]==tx){
                id=i;
                break;
            }
        }
        cout<<tx<<' ';
        FOR(i,id+2,n){
            cout<<w[i]<<' ';
        }
        FOR(i,1,id-1){
            cout<<w[i]<<' ';
        }
        cout<<tx<<endl;
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}