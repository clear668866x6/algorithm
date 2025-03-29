#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

namespace WIDA {
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
    
    // 重定义输入输出
    template <class... Args> void __(Args... args) { // 快速输出
        auto _ = [&](auto x) { cout << x << " "; };
        int arr[] = {(_(args), 0)...};
        cout << "\n";
    }
    template <class T> istream &operator>>(istream &is, vector<T> &v) { // 直接读入vector
        for (auto &x : v) is >> x;
        return is;
    }
    template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
              class = enable_if_t<!is_same<T, string>::value>>
    ostream &operator<<(ostream &os, const T &c) { // 直接输出容器
        for (auto it = c.begin(); it != c.end(); ++it)
            os << &" "[2 * (it == c.begin())] << *it;
        return os;
    }
    
    // 常用库函数重定义
    template <typename T> T min(const vector<T> &v) {
        return *min_element(v.begin(), v.end());
    }
    template <typename T> T max(const vector<T> &v) {
        return *max_element(v.begin(), v.end());
    }
    template <typename T> T acc(const vector<T> &v) {
        return accumulate(v.begin(), v.end(), T(0LL));
    }
    template <class T> void reverse(vector<T> &v) { 
        reverse(v.begin(), v.end());
    }
    template <class T> void sort(vector<T> &v) { 
        sort(v.begin(), v.end());
    }
    template <class T> void rsort(vector<T> &v) { 
        sort(v.rbegin(), v.rend());
    }
    template <class T> T mymax(T x, T y) {
        return x < y ? y : x;
    }
    template <class T> T mymin(T x, T y) {
        return x > y ? y : x;
    }
    template <class T> void cmax(T &x, T y) {
        x = mymax(x, y);
    }
    template <class T> void cmin(T &x, T y) {
        x = mymin(x, y);
    }
    template <class T> T sign(const T &a) {
        return a == 0 ? 0 : (a < 0 ? -1 : 1);
    }
    template <class T> T floor(const T &a, const T &b) {
        T A = abs(a), B = abs(b);
        assert(B != 0);
        return sign(a) * sign(b) > 0 ? A / B : -(A + B - 1) / B;
    }
    template <class T> T ceil(const T &a, const T &b) {
        T A = abs(a), B = abs(b);
        assert(b != 0);
        return sign(a) * sign(b) > 0 ? (A + B - 1) / B : -A / B;
    }
    int mypow(int n, int k, int p) {
        int r = 1;
        for (; k; k >>= 1, n = n * n % p) {
            if (k & 1) r = r * n % p;
        }
        return r;
    }
    const int N = 2e5 + 10;
    const int INF = numeric_limits<int>::max();
    const int mod = 1e9 + 7;
}

using namespace WIDA;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,k;
int ans[N];
int s[N],w[N];

void solve() {
    cin>>n>>k;

    FOR(i,1,n){
        int x;
        int sum=0;
        FOR(j,1,3){
            cin>>x;
            sum+=x;
        }
        w[i]=sum;
        s[i]=sum;
    }   

    sort(s+1,s+1+n);
    FOR(i,1,n){
        int t=upper_bound(s+1,s+1+n,w[i]+300)-s-1;//最好偏左边，如果偏右边很容易越界
        if(n-t<=k-1){
            Yes;
        }else{
            No;
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