namespace DSU{
    int p[N],siz[N];

    void init(int x){
        FOR(i,1,x)p[i]=i,siz[i]=1;
    }

    int find(int x){
        if(x!=p[x])p[x]=find(p[x]);
        return p[x];
    }

    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x!=y){
            p[x]=y;
            siz[y]+=siz[x];
        }
    }
}