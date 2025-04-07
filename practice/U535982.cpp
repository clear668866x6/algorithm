#include<bits/stdc++.h>

using namespace std;
#define N 100

int wrong_solve() {
    int n;
    cin >> n;
    n = 2*n;
    vector<char> s(n+1);
    
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    
    int t1= 0,t2=0;
    for(int i = 1; i <= n; ++i) {
        if( i % 2 == 0 && s[i] == 'A'){  //look like: ABABAB
            t1++; 
        }
        if( i % 2 != 0 && s[i] == 'A'){  //look like: BABABA
            t2++;
        }
    }
    cout << min(t1,t2) << endl; 
    return 0;
}

int solve() {
    int n;
    cin >> n;
    n = 2*n;
    vector<char> s(n+1);
    
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
    }


    int a = 0;
    for(int i = 1; i <= n; i++) {
        if(i % 2 != 0)
             if(s[i] == 'A')
                a++;
                
        
    }
    cout << min(n/2-a,a) << endl;
    
    return 0;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) wrong_solve();
}