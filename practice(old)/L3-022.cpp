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
constexpr int N = 200 + 10;
constexpr int mod = 998244353;

int __FAST_IO__ = [](){
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    return 0;
}();

int n,m,k;
int line[N];
bool isend[N];
int d[N][N];
bool vis[N][N];
map<int,int>mp[N];

void solve() {
    cin>>n>>m>>k;

    FOR(i,1,n){
        FOR(j,1,n){
            d[i][j]=1e18;
        }
        d[i][i]=0;
    }
    cin.ignore();
    FOR(i,1,m){
        int t=0,cnt=0;
        char ch;
        string s;
        getline(cin,s);
        s+=' ';
        for(auto x:s){
            if(isdigit(x)){
                t=t*10+(x-'0');
            }else{
                line[++cnt]=t;
                t=0;
            }
        }

        isend[line[1]]=isend[line[cnt]]=1;
        FOR2(i,3,cnt,2){
            int u=line[i-2],v=line[i];
            d[u][v]=min(d[u][v],line[i-1]);
            d[v][u]=min(d[v][u],line[i-1]);
        }
    }

    FOR(k,1,n){
        FOR(i,1,n){
            FOR(j,1,n){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    FOR(i,1,n){
        FOR(j,1,n){
            if(i==j||d[i][j]==1e18)continue;
            int qian=2+d[i][j]/k;
            if(!mp[i].count(qian)||mp[i][qian]<d[i][j]){
                mp[i][qian]=d[i][j];
            }
        }
    }

    int Q;
    cin>>Q;

    queue<int>q;
    while(Q--){
        int x;
        cin>>x;
        vis[x][x]=1;
        q.push(x);

        while(q.sz){
            int t=q.front();
            q.pop();

            FOR(i,1,n){
                if(vis[t][i]||d[t][i]==1e18)continue;
                if(isend[i]){
                    q.push(i);
                    vis[t][i]=1;
                }else{
                    int qian=2+d[t][i]/k;
                    if(d[t][i]==mp[t][qian]){
                        q.push(i);
                        vis[t][i]=1;
                    }
                }
            }
        }

        bool f=false;

        FOR(i,1,n){
            if(f&&vis[x][i]){
                cout<<" "<<i;
            }
            if(!f&&vis[x][i]){
                cout<<i;
                f=1;
            }
        }
        cout<<endl;
    }
}

signed main() {
    int Task = 1;
    for (; Task; Task--) {
        solve();
    }
    return 0;
}