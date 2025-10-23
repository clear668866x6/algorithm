//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")

#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define int long long
#define ll __int128
#define double long double
#define lowbit(x) (x&(-x))
#define log(x) (31^__builtin_clz(x))
#define endl '\n'

typedef pair<int,int>PII;
typedef pair<double,double>PDD;
typedef tuple<double,double,double>TDDD;
typedef tuple<int,int,int>TIII;

const int N = 2e5+10;
const int mod = 1e9+7 , P = 131;
const double PI = acos(-1);
const double eps = 1e-8;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());//随机数

int read(){
    char c=0;
    int res=0;
    int f=1;
    while(!(c>='0'&&c<='9')){
        if(c=='-'){
            f=-f;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        res=(res<<3)+(res<<1)+c-'0';
        c=getchar();
    }
    return res*f;
}

void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(char(x%10+'0'));
}

int n,m,k;
vector<PII>G[N];
PII p[N];
int cnt,siz[N],mx[N];
int rt,tot,ans=1e18;
bool vis[N];
int t;

void dfs1(int u,int fa){
    siz[u]=1,mx[u]=0;
    for(auto& [j,w]:G[u]){
        if(j==fa||vis[j])continue;
        dfs1(j,u);
        siz[u]+=siz[j];
        mx[u]=max(mx[u],siz[j]);
    }
    mx[u]=max(mx[u],tot-siz[u]);
    if(mx[u]<mx[rt])rt=u;
}

void dfs2(int u,int fa,int a,int b){//a为权值和（距离和）||b为边数
    if(b>ans||a>k)return;
    p[++cnt]={a,b};
    for(auto& [j,w]:G[u]){
        if(j==fa||vis[j])continue;
        dfs2(j,u,a+w,b+1);
    }
}

void calc(int x,int s){
    tot=s;
    rt=0;
    dfs1(x,x);
    vis[rt]=1;
    set<PII>st;
    st.insert({0,0});

    for(auto& [j,w]:G[rt]){
        if(vis[j])continue;
        cnt=0;
        dfs2(j,rt,w,1);
        for(int i=1;i<=cnt;i++){
            auto it=st.lower_bound({k-p[i].x,0});
            if(it!=st.end()&&it->first+p[i].x==k){
                t++;
                // ans=min(ans,p[i].y+it->second);
            }
        }
        for(int i=1;i<=cnt;i++)st.insert(p[i]);
    }
    st.clear();

    for(auto& [j,w]:G[rt]){
        if(vis[j])continue;
        calc(j,siz[j]);
    }
}

void solve(){
    cin>>n>>k;
    k--;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b;
        G[a].emplace_back(b,1);
        G[b].emplace_back(a,1);
    }
    
    ans=1e18;
    mx[0]=1e18;
    calc(1,n);
    cout<<t<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    T=1;
    while(T--)solve();

#ifdef PURPLE
    cerr<<fixed<<setprecision(10)<<1.0*clock()/CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}