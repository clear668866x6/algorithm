namespace diamitor{
    VI g[N];
    int mx=-1;

    void dfs(int u,int fa,int d[],int &p){
        for(auto& j:g[u]){
            if(j==fa)continue;
            d[j]=d[u]+1;
            if(d[j]>mx)mx=d[j],p=j;
            dfs(j,u,d,p);
        }
    }

    void work(){
        int A=0,B=0,C=0;//A,B为两个端点
        dfs(1,0,d1,A);
        d1[1]=0;
        mx=-1;
        dfs(A,0,d1,B);
        dfs(B,0,d2,C);
        
    }
}