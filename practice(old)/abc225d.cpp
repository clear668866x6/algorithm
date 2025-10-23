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

int r[N],l[N];
int h=0,e=1e5+1;
int n,q;

void add(int x,int y){
    r[x]=y;
    l[y]=x;
}

void solve() {
    cin>>n>>q;

    FOR(i,1,n){
        add(i,e);
        add(h,i);
    }

    while(q--){
        int op,x,y;
        cin>>op>>x;
        if(op==1){
            cin>>y;
            add(x,y);
        }else if(op==2){
            cin>>y;
            add(x,e);
            add(h,y);
        }else{
            int pos=x,cnt=1;
            while(l[pos]!=h){
                pos=l[pos];
                cnt++;
            }
            int t=x;
            while(r[t]!=e){
                t=r[t];
                cnt++;
            }
            cout<<cnt<<' ';
            for(int i=pos;i!=e;i=r[i]){
                cout<<i<<' ';
            }
            cout<<endl;
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