#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve() {
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    
    int ans=abs(ty-sy);

    if(((sx+sy)&1)&&((tx+ty)&1)){
        //s在中右，t在中右
        if(abs(tx-sx)>ans){
            ans+=(abs(tx-sx)-ans)/2;
        }
    }else if(((sx+sy)&1)&&!((tx+ty)&1)){
        //s在中右，t在中左
        if(abs(tx-sx)>ans){
            ans+=(abs(tx-sx+1)-ans)/2;
        }
    }else if(!((sx+sy)&1)&&((tx+ty)&1)){
        //s在中左，t在中右
        // cout<<(abs(tx-ty)-ans+1)/2<<endl;
        if(abs(tx-sx)>ans){
            ans+=(abs(tx-sx-1)-ans)/2;
        }
    }else{
        if(abs(tx-sx)>ans){
            ans+=(abs(tx-sx)-ans)/2;
        }
    }

    cout<<ans;

}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}