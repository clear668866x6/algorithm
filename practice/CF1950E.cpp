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
    int n;
    string s;
    cin>>n>>s;
    s=' '+s;

    int ans=n;

    function<bool(int)> check=[&](int x){
        if(x==n)return true;
        string a=" ",b=" ";
        FOR(i,1,x)a+=s[i];
        FOR(i,n-x+1,n)b+=s[i];
        int cnt1=0,cnt2=0,j=1;

        FOR(i,1,n){
            if(j>x)j=1;
            if(s[i]!=a[j])cnt1++;
            j++;
        }
        j=1;
        FOR(i,1,n){
            if(j>x)j=1;
            if(s[i]!=b[j])cnt2++;
            j++;
        }
        if(cnt1>1&&cnt2>1)return false;
        return true;
    };

    FOR(i,1,n/i){
        if(n%i==0){
            if(check(i))ans=min(ans,i);
            if(check(n/i))ans=min(ans,n/i);
        }
    }
    cout<<ans<<endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    while (Task--) {
        solve();
    }

    return 0;
}