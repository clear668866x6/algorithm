
int dfs(int u,int top,bool lim){
    if(!u)return 1;
    if(!lim&&f[u][top]!=-1)return f[u][top];
    int mx=(lim?num[u]:9);
    int ans=0;
    for(int i=0;i<=mx&&i<top;i++){
        ans+=dfs(u-1,(top==10&&i!=0)?i:top,i==mx&&lim);
    }

    if(!lim)f[u][top]=ans;

    return ans;
}

/*
最好不要对受限状态进行转移

这是因为 f[u][top][true] 的值，对于同一个 u 和 top，可能在不同的 lim 为 true 的路径下代表不同的意义。

具体来说，当 lim 为 true 时，mx 的值 num[u] 是变化的，这意味着 dfs 在受限状态下并不是一个纯函数，它的结果依
赖于 num[u] 的具体值，而不仅仅是 u 和 top。
例如，当你计算 calc(123) 时，在处理百位时 u=3, lim=true, num[3]=1。在处理十位时 u=2, lim=true, num[2]=2。
虽然 u 和 top 可能相同，但 num[u] 的值不同，导致 mx 不同，从而导致结果不同。
*/