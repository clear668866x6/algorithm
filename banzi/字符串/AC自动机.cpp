namespace ACauto{
    string s;
    int q,n;
    int id[N];
    int tr[N][30],ne[N];
    int cnt[N],idx;
    bool vis[N];
    
    int insert(string t){
        int p=0;
        FOR(i,0,t.sz-1){
            int u=t[i]-'a';
            if(!tr[p][u])tr[p][u]=++idx;
            p=tr[p][u];
        }
        cnt[p]++;
        return p;
    }
    
    void build(){
        queue<int>q;
        FOR(i,0,25){
            if(tr[0][i])q.push(tr[0][i]);
        }
    
        while(q.sz){
            int t=q.front();
            q.pop();
    
            FOR(i,0,25){
                int j=tr[t][i];
                if(j)ne[j]=tr[ne[t]][i],q.push(j);
                else tr[t][i]=tr[ne[t]][i];
            }
        }
    }
    
    void query(string s){
        int ans=0,t=0;
        FOR(k,0,s.sz-1){
            t=tr[t][s[k]-'a'];
            for(int j=t;j&&~cnt[j];j=ne[j]){
                vis[j]=1;
                cnt[j]=-1;
            }
        }
    }
}
/*
可用于查找关键字，用的方法就是字典树多了个ne指针，就像KMP

*/