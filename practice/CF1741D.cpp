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
constexpr int N = 3e5 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,w[N];
//反思：其实已经想到了每层来，也就是按2^k的方式来，已经打算尝试了，但最后没有自己去写，下次得注意一下，有思路了不要看解题

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    FOR2(i,2,n,2){
        if(abs(w[i]-w[i-1])!=1){
            cout<<-1<<endl;
            RE;
        }
    }

    int ans=0;

    FOR2(i,2,n,2){
        if(w[i]<w[i-1]){
            ans++;
            swap(w[i],w[i-1]);
        }
    }

    for(int i=4;i<=n;i*=2){
        for(int j=i;j<=n;j+=i){
            if(w[j-i/2]>w[j]){
                swap(w[j-i/2],w[j]);
                ans++;
            }
            if(abs(w[j]-w[j-i/2])!=i/2){
                cout<<-1<<endl;
                RE;
            }
        }
    }

    cout<<ans<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}