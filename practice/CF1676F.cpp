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
int w[N];

void solve() {
    cin>>n>>k;
    
    map<int,int>mp;
    int t=0;
    FOR(i,1,n)cin>>w[i],mp[w[i]]++,t=max(t,mp[w[i]]);
    
    if(t<k){
        cout<<-1<<endl;
        RE;
    }

    sort(w+1,w+1+n);

    FOR(i,1,n){
        if(mp[w[i]]>=k){
            t=w[i];
            break;
        }
    }

    int l=t,r=t;
    int ans=0,ansl=t,ansr=t;

    for(auto [x,y]:mp){
        if(y>=k){
            if(r+1!=x){
                if(r-l>ans){
                    ans=r-l;
                    ansl=l,ansr=r;
                }
                l=x,r=x;
            }else{
                r++;
            }
        }
    }

    if(r-l>ans){
        ansl=l,ansr=r;
        ans=r-l;    
    }

    if(!ans){
        FOR(i,1,n){
            if(mp[w[i]]>=k){
                ansl=ansr=w[i];
                break;
            }
        }
    }

    cout<<ansl<<' '<<ansr<<endl;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}