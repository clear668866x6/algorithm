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

int n,w[N],b[N];

int mexa(int l,int r){
    set<int>mp;

    int mex=0;

    FOR(i,l,r){
        mp.insert(w[i]);
        while(mp.count(mex))mex++;
    }
    return mex;
}

int mexb(int l,int r){
    set<int>mp;

    int mex=0;

    FOR(i,l,r){
        mp.insert(b[i]);
        while(mp.count(mex))mex++;
    }
    return mex;
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i],b[i]=w[i];

    sort(w+1,w+1+n);

    int cnt=0;

    do{

        bool f=false;

        FOR(l,1,n){
            FOR(r,l,n){
                if(mexa(l,r)!=mexb(l,r)){
                    f=1;
                    break;
                }
            }
            if(f)break;
        }
        if(!f){
            cnt++;
            FOR(i,1,n)cout<<w[i]<<" \n"[i==n];
        }
    }while(next_permutation(w+1,w+1+n));


    cout<<cnt<<endl;

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}