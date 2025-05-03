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

int n,m;
struct E{
    int l,r;
    bool operator<(const E& t)const{
        return l<t.l;
    }
}w[N];

bool check(int x){
    int idx=1,cur=w[1].l;

    FOR(i,2,n){
        if(idx>m)return false;
        if(cur+x>w[idx].r){
            while(idx<m&&w[idx].r<cur+x)idx++;
            if(w[idx].r<cur+x)return false;
            if(w[idx].l>=cur+x){
                cur=w[idx].l;
            }else{
                cur+=x;
            }
        }else{
            cur+=x;
        }
    }

    return true;
}

void solve() {
    cin>>n>>m;

    FOR(i,1,m){
        cin>>w[i].l>>w[i].r;
    }

    sort(w+1,w+1+m);

    int l=0,r=1e12;

    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}