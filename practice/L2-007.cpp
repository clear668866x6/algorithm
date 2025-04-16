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

int p[N],n;
struct E{
    int id,num;
    double cnt,s;
    bool operator<(const E& t)const{
        if(s==t.s)return id<t.id;
        return s>t.s;
    }
}w[N];
struct Q{
    double a,b;
}t[N];

int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}

void uni(int a,int b){
    int pa=find(a),pb=find(b);
    if(pa>=pb){
        p[pa]=pb;
    }else{
        p[pb]=pa;
    }
}

void solve() {
    cin>>n;

    FOR(i,1,10000)p[i]=i;

    set<int> vis;

    FOR(i,1,n){
        int id;
        int p,q,k;
        cin>>id>>p>>q;
        cin>>k;
        vis.insert(id);

        if(p>=0){
            vis.insert(p);
            uni(id,p);
        }

        if(q>=0){
            vis.insert(q);
            uni(id,q);
        }

        FOR(j,0,k-1){
            int son;
            cin>>son;
            vis.insert(son);
            uni(id,son);
        }

        double house,s;
        cin>>house>>s;

        t[id]={house,s};
    }

    set<int>a;

    for(auto x:vis){
        if(find(x)==x)a.insert(x);
    }

    vector<E>mp;

    for(auto x:vis){
        int id=find(x);
        w[id].id=id;
        w[id].num++;
        w[id].cnt+=t[x].a;
        w[id].s+=t[x].b;
    }

    for(auto x:a){
        mp.pb(E{w[x].id,w[x].num,w[x].cnt/(double)w[x].num,w[x].s/(double)w[x].num});
    }

    sort(ALL(mp));

    printf("%lld\n",mp.sz);
    for(auto [a,b,c,d]:mp){
        printf("%04lld %lld %.3lf %.3lf\n",a,b,c,d);
    }

}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}