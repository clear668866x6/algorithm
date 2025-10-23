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

int n;

int qmi(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

void solve() {
    cin>>n;

    if(n<=10){
        cout<<n-1<<endl;
        RE;
    }

    int t=n,cnt=0;
    while(t)t/=10,cnt++;
    cnt--;
    int p=qmi(10,cnt);

    if(to_string(n-p).sz==cnt+1){
        string a=to_string(n-p);
        cout<<a;
        a.pop_back();
        reverse(ALL(a));
        cout<<a;
    }else if(to_string(n-p).sz==cnt){
        string a=to_string(n-p);
        cout<<a;
        reverse(ALL(a));
        cout<<a;
    }else{
        p/=10;
        n-=p;
        string a=to_string(n);
        cout<<a;
        a.pop_back();
        reverse(ALL(a));
        cout<<a;
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}