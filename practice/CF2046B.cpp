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

int n,w[N];
struct E{//双 priority_queue 模拟可删堆
    priority_queue<int,VI,greater<int>>q1,q2;

    void clear(){
        while(q1.sz)q1.pop();
        while(q2.sz)q2.pop();
    }

    bool empty(){
        return !(q1.sz-q2.sz);
    }

    void push(int x){
        q1.push(x);
    }

    void pop(int x){
        q2.push(x);
    }

    int top(){
        while(q1.sz&&q2.sz&&q1.top()==q2.top()){
            q1.pop(),q2.pop();
        }
        return q1.top();
    }
}q1,q2;

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    q1.clear(),q2.clear();
    FOR(i,1,n)q1.push(w[i]);

    FOR(i,1,n){
        if(w[i]==q1.top())cout<<w[i]<<" ";
        else{
            q1.push(w[i]+1);
            q2.push(w[i]+1);
        }
        q1.pop(w[i]);
    }

    while(!q2.empty()){
        cout<<q2.top()<<" ";
        q2.pop(q2.top());
    }
    cout<<endl;
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task--) {
        solve();
    }
    return 0;
}