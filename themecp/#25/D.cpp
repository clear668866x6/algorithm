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

int n,m,a[N],b[N];

void solve() {
    cin>>n>>m;

    FOR(i,1,n)cin>>a[i];
    FOR(i,1,m)cin>>b[i];

    priority_queue<int>q;

    int s1=0,s2=0;

    FOR(i,1,n)s1+=a[i];
    FOR(i,1,m)q.push(b[i]),s2+=b[i];

    if(s1!=s2){
        No;
        RE;
    }

    sort(a+1,a+1+n,greater());

    int i=1;
    while(q.sz){
        int x=q.top();
        q.pop();

        if(x<a[i]){
            No;
            RE;
        }

        if(a[i]==x)i++;
        else{
            q.push(x/2);
            q.push((x+1)/2);
        }
    }
    Yes;

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}