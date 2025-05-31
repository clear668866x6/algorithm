/*
我们用 $k$ 表示字符串中羊的数量，用 $x_1, x_2, \ldots, x_k$ ( $1 \le x_1 &lt; x_2 &lt; \ldots &lt; 
x_k \le n$ ) 表示它们在字符串中的位置。

请注意，在最优解中，数字为 $m = \lceil\frac{n}{2}\rceil$ 的羊不会移动。这可以通过考虑数字为 $m$ 的羊至少走
一步棋的最优解来证明，并得出这个解不是最优解的结论。考虑数字为 $i=1$ 至 $n$ 的羊。那么 $i$ /th的羊的最终位
置将是 $x_m - m + i$ ，答案将是 $\sum\limits_{i=1}^{k} |x_i - (x_m - m + i)|$ 。

*/
void solve() {
    cin>>n>>s;

    int cnt=-1,pos=-1,t=0;

    for(auto x:s){
        t+=(x=='*');
    }

    FOR(i,0,n-1){
        if(s[i]=='*'){
            cnt++;
            if(cnt==t/2){
                pos=i;
            }
        }
    }

    int mid=pos-t/2,ans=0;

    FOR(i,0,n-1){
        if(s[i]=='*'){
            ans+=abs(mid-i);
            mid++;
        }
    }
    cout<<ans<<endl;

}