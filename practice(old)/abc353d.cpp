#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

int qmi(int a,int b,int mod=998244353){
    int res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    V<int>w(n+1);
    FOR(i,1,n)cin>>w[i];

    V<int>pre1(n+1,0),pre2(n+1,0);

    FOR(i,1,n){
        pre1[i]=pre1[i-1]+qmi(10,(int)(to_string(w[i]).sz));
        pre2[i]=pre2[i-1]+w[i];
    }

    int ans=0;

    FOR(i,1,n-1){
        (ans+=w[i]*((pre1[n]-pre1[i])%998244353+998244353)%998244353+pre2[n]-pre2[i])%=998244353;
    }
    cout<<ans;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}