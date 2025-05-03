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

int n,k;
string s;

void solve() {
    cin>>n>>k>>s;

    int m=0;

    for(auto x:s)m+=(x=='1');

    if((1ll<<k)-m<0){
        cout<<"None"<<endl;
    }else{
        string ans="2222222222222222222222222222222222";

        FOR(i,0,k){
            int cur=m+i,num=0;
            string p;
            while(cur){
                if(cur%2){
                    num++;
                    p+='1';
                }else{
                    p+='0';
                }
                cur/=2;
                if(p.sz>=k)break;
            }
            while(p.sz<k)p.pb('0');
            reverse(ALL(p));
            if(num==i){
                ans=min(ans,p);
            }
        }
        if(ans=="2222222222222222222222222222222222"){
            cout<<"None"<<endl;
        }else{
            cout<<ans<<endl;
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