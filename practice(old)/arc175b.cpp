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

int n,a,b;
string s;

void solve() {
    cin>>n>>a>>b>>s;

    stack<char>stk;

    s=' '+s;

    a=min(a,2*b);

    n*=2;

    FOR(i,1,n){
        if(s[i]=='('){
            stk.push(s[i]);
        }else{
            bool f=false;
            if(stk.sz&&stk.top()=='(')stk.pop(),f=1;
            if(!f)stk.push(s[i]);
        }
    }

    vector<char>t;

    while(stk.sz){
        t.pb(stk.top());
        stk.pop();
    }

    if(!t.sz){
        cout<<0<<endl;
        RE;
    }

    reverse(ALL(t));
    
    int tl=0,tr=0;

    for(auto x:t){
        if(x=='(')tl++;
        if(x==')')tr++;
    }

    int m=t.sz;

    int ans=abs(m/2-tl)*b;

    int l=0,r=m-1;

    while(t[l]==')'&&t[r]=='('){
        ans+=a;
        l+=2,r-=2;
    }

    cout<<ans<<endl;
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}