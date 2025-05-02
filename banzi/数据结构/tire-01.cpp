
struct Tire{
    int tr[N*30][2],pos[N*30],idx;

    void clear(){
        FOR(i,1,idx)tr[i][0]=tr[i][1]=pos[i]=0;
        idx=1;
    }

    void insert(int x,int y){
        int p=1;
        FORD(i,0,30){
            int t=x>>i&1;
            if(!tr[p][t])tr[p][t]=++idx;
            p=tr[p][t];
            pos[p]=max(pos[p],y);
        }
    }

    int query(int x){
        int p=1,ans=0,mx=-1;
        FORD(i,0,30){
            int t=x>>i&1;
            if(tr[p][t^1]){
                if((ans+(1<<i))>=m)mx=max(mx,pos[tr[p][t^1]]),p=tr[p][t];
                else p=tr[p][t^1],ans+=(1<<i);
            }else if(tr[p][t])p=tr[p][t];
            else break;
        }
        return mx;
    }
}t;