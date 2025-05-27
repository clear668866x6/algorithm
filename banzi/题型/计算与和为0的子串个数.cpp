//只要某一个区间和为0，则所有包含该区间的和都为0
/*
固定r的i形式，反正我第一次见

*/
void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i];

    int ans=0;
    
    FOR(i,1,n){//固定r的情况
        FOR(k,0,30){
            if(!(w[i]>>k&1)){
                lst[k]=i;
            }
        }

        ans+=*min_element(lst,lst+31);
    }
    cout<<ans;
}