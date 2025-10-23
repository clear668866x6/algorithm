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

int n,k,w[N];

void solve() {
    cin>>n>>k;

    FOR(i,1,n)cin>>w[i];

    int tot=0;

    FOR(i,1,n)tot+=w[i];

    int mx=*max_element(w+1,w+1+n),mn=*min_element(w+1,w+1+n);

    if(mx-mn>k){
        FOR(i,1,n){
            if(w[i]==mx){
                w[i]--;
                break;
            }
        }
        int t=*max_element(w+1,w+1+n);
        if(t==mx||t-mn>k){
            cout<<"Jerry"<<endl;
            RE;
        }
        if(tot&1){
            cout<<"Tom"<<endl;
        }else{
            cout<<"Jerry"<<endl;
        }
    }else{
        if(tot&1){
            cout<<"Tom"<<endl;
        }else{
            cout<<"Jerry"<<endl;
        }
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}