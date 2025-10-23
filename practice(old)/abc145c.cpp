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
} // namespace WIDA

using namespace WIDA;

namespace QuickRead {
    char buf[1 << 21], *p1 = buf, *p2 = buf;
    inline int getc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <typename T> void Cin(T &a) {
        T ans = 0; bool f = 0; char c = getc();
        for (; c < '0' || c > '9'; c = getc()) if (c == '-') f = 1;
        for (; c >= '0' && c <= '9'; c = getc()) ans = ans * 10 + c - '0';
        a = f ? -ans : ans;
    }
    template <typename T, typename... Args> void Cin(T &a, Args &...args) {
        Cin(a), Cin(args...);
    }
    template <typename T> void write(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) write(x / 10);
        putchar(x % 10 + '0');
    }
    
    using i128 = __int128_t;
    i128 abs(const i128 &x) {
        return x > 0 ? x : -x;
    }
    auto &operator>>(istream &it, i128 &j) {
        string val; it >> val;
        reverse(val.begin(), val.end());
        i128 ans = 0;
        bool f = 0; char c = val.back(); val.pop_back();
        for (; c < '0' || c > '9'; c = val.back(), val.pop_back()) if (c == '-') f = 1;
        for (; c >= '0' && c <= '9'; c = val.back(), val.pop_back()) ans = ans * 10 + c - '0';
        j = f ? -ans : ans;
        return it;
    }
    auto &operator<<(ostream &os, const i128 &j) {
        string ans;
        function<void(i128)> write = [&](i128 x) {
            if (x < 0) ans += '-', x = -x;
            if (x > 9) write(x / 10);
            ans += x % 10 + '0';
        };
        write(j);
        return os << ans;
    }
} // namespace QuickRead

using namespace QuickRead;

const int Max = numeric_limits<int>::max();
const int Min = numeric_limits<int>::min();

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

namespace Random { // 随机数生成器
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    int prr(int a, int b) { return rnd() % (b - a + 1) + a; }
} // namespace Random

using namespace Random;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n;
int x[10],y[10];
double ans;
bool vis[10];

double dist(int x1,int y1,int x2,int y2){
    int dx=x1-x2;
    int dy=y1-y2;
    return sqrt(dx*dx+dy*dy);
}

void dfs(int u,double s,int lst){
    if(u==n){
        ans+=s;
        return;
    }

    FOR(i,1,n){
        if(vis[i])continue;
        vis[i]=1;
        dfs(u+1,s+dist(x[i],y[i],x[lst],y[lst]),i);
        vis[i]=0;
    }

}

void solve() {
    cin>>n;

    FOR(i,1,n){
        cin>>x[i]>>y[i];
    }

    FOR(i,1,n){
        vis[i]=1;
        dfs(1,0,i);
        vis[i]=0;
    }

    int p=1;

    FOR(i,1,n){
        p=p*i;
    }

    printf("%.12lf",ans/(double)p);

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}