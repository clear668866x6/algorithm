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
constexpr int N = 2e6 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

namespace manacher{
    char s[N],a[N];
    int p[N],n,m;

    void init(){
        m=0;
        s[m++]='$',s[m++]='#';
        FOR(i,0,n-1)s[m++]=a[i],s[m++]='#';
        s[m++]='^';
        n=m;
    }

    void work(){
        int mr=0,mid;

        FOR(i,0,n-1){
            if(i<mr)p[i]=min(p[mid*2-i],mr-i);
            else p[i]=1;
            while(s[i-p[i]]==s[i+p[i]])p[i]++;
            if(i+p[i]>mr){
                mr=i+p[i];
                mid=i;
            }
        }
    }
}

using namespace manacher;

void solve() {
    cin>>a;

    n=strlen(a);

    init();

    work();

    int ans=0;

    FOR(i,0,n-1){
        ans=max(ans,p[i]);
    }

    int mid=0;

    FOR(i,0,n-1){
        if(ans==p[i]){
            mid=i;
        }
    }

    int l=mid-p[mid]+2;
    int r=p[mid]+mid-2;

    // cout<<l<<' '<<r<<endl;

    // cout<<s;

    FOR2(i,l,r,2){
        cout<<s[i];
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}