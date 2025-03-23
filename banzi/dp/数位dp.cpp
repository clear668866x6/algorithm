namespace shuweidp{
    int f[20][20][2][2];//含前导0的
    int num[20],cnt;

    int dfs(int u,int sum,bool limit,bool lead){
        if(!u) return sum;
        if(~f[u][sum][limit][lead]) return f[u][sum][limit][lead];
        int res=0;
        for(int i=0;i<=(limit?num[u]:9);i++){
            if(lead&&!i) res+=dfs(u-1,sum,0,1);
            else res+=dfs(u-1,sum+(i==1),limit&&(i==num[u]),0);
        }
        return f[u][sum][limit][lead]=res;
    }

    int work(int x){
        cnt=0;
        memset(f,-1,sizeof f);
        while(x) num[++cnt]=x%10,x/=10;
        return dfs(cnt,0,1,1);
    }
}