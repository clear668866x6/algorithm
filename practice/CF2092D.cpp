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

int n;
string s;

/*
思路：T I 之间可以放L，但如果你在L的左边和右边都放的话，此时就会出现TIL的情况，这个就跟没操作是一样的。

所以我们肯定是要么在左边使jin放TITITIT，要么在右边放。
*/

//正难则反，因为如果我们只贪心的去想的话，会出现：TTILL，会误认为是错的，但其实它可以通过在TI之间加个T就可以了。

//此时为了避免上述情况，我们就类似， L=2,T=1,L=1，L减少1,此时TL同时增加（就是类似相对量）

void solve() {
    cin>>n>>s;

    VI a(n,0),cnt(3,0);

    FOR(i,0,n-1){
        if(s[i]=='L')a[i]=1;
        if(s[i]=='T')a[i]=2;
    }

    FOR(i,0,n-1){
        cnt[a[i]]++;
    }

    int mn=*min_element(ALL(cnt));
    VI ans;

    FOR(i,0,a.sz-2){
        if(a[i]==a[i+1])continue;
        int t=3-a[i]-a[i+1];
        if(cnt[a[i]]>mn){
            VI b=a;
            int rd=cnt[a[i]]-mn;
            cnt[a[i]]=mn;
            a.resize(n+rd*2);
            FOR(j,0,rd-1){
                a[i+2*j+1]=a[i+1];
                a[i+2*j+2]=t;
                ans.pb(i);
                ans.pb(i);
            }
            FOR(j,i+rd*2+1,a.sz-1){
                a[j]=b[j-rd*2];
            }
        }else if(cnt[a[i+1]]>mn){
            VI b=a;
            int rd=cnt[a[i+1]]-mn;
            cnt[a[i+1]]=mn;
            a.resize(n+rd*2);
            FOR(j,0,rd-1){
                a[i+2*j+1]=t;
                a[i+2*j+2]=a[i];
                ans.pb(i+2*j);
                ans.pb(i+2*j+1);
            }
            FOR(j,i+rd*2+1,a.sz-1){
                a[j]=b[j-rd*2];
            }
        }
    }

    if(cnt[0]==cnt[1]&&cnt[0]==cnt[2]){
        cout<<ans.sz<<endl;
        for(auto x:ans)cout<<(x+1)<<endl;
    }else{
        cout<<-1<<endl;
    }

}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}