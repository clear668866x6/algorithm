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

int n,m;

void solve() {
    cin>>n>>m;

    VI w;

    FOR(i,1,n){
        int x;
        cin>>x;
        w.pb(x);
        push_heap(ALL(w),greater());
    }

    cin.ignore();
    while(m--){
        string b;
        stringstream ss;
        ss.clear();
        getline(cin,b);
        ss<<b;
        if(b.find("root")!=-1){
            int a;
            ss>>a;
            if(a!=w[0]){
                cout<<"F"<<endl;
            }else{
                cout<<"T"<<endl;
            }
            continue;
        }

        int c=0;

        bool f=false;

        if(b.find("siblings")!=-1){
            int a,c;
            string t;
            ss>>a>>t>>c;
            FOR(i,0,w.sz-1){
                if(w[i]==a){
                    int t=(i%2==1)?i+1:i-1;
                    if(w[t]==c)f=1;
                    break;
                }
                if(w[i]==c){
                    int t=(i%2==1)?i+1:i-1;
                    if(w[t]==a)f=1;
                    break;
                }
            }
        }

        if(b.find("parent")!=-1){
            int a,c;
            string t1,t2,t3,t4;
            ss>>a>>t1>>t2>>t3>>t4>>c;
            FOR(i,0,w.sz-1){
                if(w[i]==a){
                    if(i*2+1<w.sz&&w[i*2+1]==c){
                        f=1;
                        break;
                    }
                    if(i*2+2<w.sz&&w[i*2+2]==c){
                        f=1;
                        break;
                    }
                }
            }
        }

        if(b.find("child")!=-1){
            int a,c;
            string t1,t2,t3,t4;
            ss>>a>>t1>>t2>>t3>>t4>>c;
            FOR(i,0,w.sz-1){
                if(w[i]==c){
                    if(i*2+1<w.sz&&w[i*2+1]==a){
                        f=1;
                        break;
                    }
                    if(i*2+2<w.sz&&w[i*2+2]==a){
                        f=1;
                        break;
                    }
                }
            }
        }

        if(f){
            cout<<"T"<<endl;
        }else{
            cout<<"F"<<endl;
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