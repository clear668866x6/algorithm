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

void solve() {
    cin>>n;

    FOR(i,1,n){
        string a,b;
        cin>>a>>b;
    
        int t1=0,t2=0;

        int c1=atoi(a.c_str()),c2=atoi(b.c_str());

        for(auto x:a)t1+=(x-'0');
        for(auto x:b)t2+=(x-'0');

        bool f1=false,f2=false;

        if(c1%t2==0){
            f1=true;
        }
        if(c2%t1==0){
            f2=true;
        }

        if(f1&&f2||(!f1&&!f2)){
            if(c1>c2){
                cout<<"A"<<endl;
            }else{
                cout<<"B"<<endl;
            }
        }else{
            if(f1&&!f2){
                cout<<"A"<<endl;
            }

            if(!f1&&f2){
                cout<<"B"<<endl;
            }
        }
    
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}