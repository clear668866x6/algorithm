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
    // cout << fixed << setprecision(12);
    return 0;
}();

int n;
char c;
string s;

void solve() {
    map<pair<int,char>,int>S;
    map<int,int>mp;
    int ans=0,tot=0;
    while(cin>>n>>c>>s,n!=0){
        if(c=='E'){
            if(S[{n,'S'}]){
                S[{n,'S'}]=0;
                int t=((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
                ans++,tot+=(t-mp[n]);
            }
            continue;
        }
        S[{n,c}]=1;    
        int t=((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
        mp[n]=t;
    }
    if(!ans){
        // cout<<0<<' '<<0<<endl;
        printf("0 0\n");
        RE;
    }
    // cout<<ans<<' '<<tot/ans<<endl;
    // cout<<ans<<' ';
    printf("%lld %.0lf\n",ans,(double)tot/(double)ans);
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}