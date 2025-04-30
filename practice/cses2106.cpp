#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"
using PII = pair<int, int>;
using TII = tuple<int, int, int>;
using ull = unsigned long long;
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
constexpr int mod = 1e9 + 7;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

string s;
int n;
ull h[N],p[N];

void init(){
    p[0]=1;
    FOR(i,1,n){
        p[i]=p[i-1]*131;
        h[i]=h[i-1]*131+s[i-1]-'a';
    }
}

ull query(int l,int r){
    return h[r+1]-h[l]*p[r-l+1];
}

int ansl,ansr,ans;

bool check(int x){
    unordered_map<ull,bool>mp;
    bool f=false;
    for(int i=0;i+x-1<n;i++){
        ull s=query(i,i+x-1);
        if(mp[s]==1){
            ansl=i,ansr=i+x-1;
            f=1;
        }else{
            mp[s]=1;
        }
    }
    return f;
}

void solve() {
    cin>>s;
    n=s.sz;
    init();

    int l=0,r=n;

    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }

    if(l<=0)cout<<-1<<endl;
    else{
        FOR(i,ansl,ansr){
            cout<<s[i];
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