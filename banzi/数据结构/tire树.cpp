namespace TireTree{
    int tr[N][30],cnt[N],idx;

    void insert(string s){
        int p=0;
        for(auto x:s){
            x-='a';
            if(!tr[p][x])tr[p][x]=++idx;
            p=tr[p][x];
        }
        cnt[p]++;
    }
}