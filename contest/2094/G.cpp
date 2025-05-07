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

int Q;

void solve() {
    cin>>Q;

    deque<int>q;
    int rev=0;
    int sum1=0,sum2=0,cnt=0;
    
    while(Q--){
        int op;
        cin>>op;
        if(op==1){
            int t;
            if(rev){
                t=q.front();
                q.pop_front();
                q.push_back(t);
            }else{
                t=q.back();
                q.pop_back();
                q.push_front(t);
            }

            sum1+=sum2-t*cnt;

        }else if(op==2){
            rev^=1;
            sum1=(cnt+1)*sum2-sum1;
        }else{
            int x;
            cin>>x;
            if(rev){
                q.push_front(x);
            }else{
                q.push_back(x);
            }
            cnt++;
            sum1+=cnt*x;
            sum2+=x;
        }
        cout<<sum1<<endl;
    }
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}