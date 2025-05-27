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
constexpr int N = 2e7 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int primes[N],cnt;
bool vis[N];

void init(int x){
    FOR(i,2,x){
        if(!vis[i])primes[cnt++]=i;
        for(int j=0;i*primes[j]<=x;j++){
            vis[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }
}

int s;
/*
输入数据：
1
4952560
你的输出 (my_output.txt):
3
2 + 7 + 4952551 = 4952560
正确输出 (correct_output.txt):
2
17 + 4952543 = 4952560
--- 错误已发现，停止对拍 ---



*/
void solve() {
    cin>>s;

    if(s==0){
        cout<<1<<endl;
        cout<<s<<" = "<<s<<endl;
        RE;
    }

    VI ans;

    int p=s;
    while(s){
        int t=upper_bound(primes,primes+cnt,s)-primes-1;
        if(t<0){
            if(s){
                ans.pb(1);
                break;
            }
        }
        ans.pb(primes[t]);
        s-=primes[t];
    }

    sort(ALL(ans));

    cout<<ans.sz<<endl;
    FOR(i,0,ans.sz-2){
        cout<<ans[i]<<" + ";
    }
    cout<<ans[ans.sz-1]<<" = "<<p<<endl;
}

signed main() {
    int Task = 1;
    init(1e7);
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}