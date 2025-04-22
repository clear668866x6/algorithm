namespace kechijiuSegmentTree{
    //可持久化线段树模板
    struct E{
        int l,r,sum;
    }tr[N*40];
    int n,m,w[N];
    int cnt,cur=1;
    
    void modify(int& rt,int k,int v,int l=0,int r=n-1){
        tr[cur]={tr[rt].l,tr[rt].r,tr[rt].sum+v};
        rt=cur,cur++;
        
        if(l==r){
            RE;
        }
        
        int mid=l+r>>1;
        
        if(k<=mid)modify(tr[rt].l,k,v,l,mid);
        else modify(tr[rt].r,k,v,mid+1,r);
    }
    
    int query(int u,int l,int r,int L=0,int R=n-1){
        if(L>=l&&R<=r){
            return tr[u].sum;
        }
        
        int mid=L+R>>1;
        
        int res=0;
        
        if(l<=mid)res+=query(tr[u].l,l,r,L,mid);
        if(r>mid)res+=query(tr[u].r,l,r,mid+1,R);
        return res;
    }
        
    void solve() {
        cin>>n>>m;
        
        FOR(i,0,n-1)cin>>w[i];
        
        VI ver;
        ver.pb(0);
        
        FOR(i,0,n-1){
            modify(ver[0],i,w[i]);
        }
        
        while(m--){
            int op;
            cin>>op;
            if(op==1){
                int k,a,x;
                cin>>k>>a>>x;
                k--;
                a--;
                modify(ver[k],a,x-query(ver[k],a,a));
            }else if(op==2){
                int k,a,b;
                cin>>k>>a>>b;
                k--,a--,b--;
                cout<<query(ver[k],a,b)<<endl;
            }else{
                int k;
                cin>>k;
                ver.pb(ver[k-1]);
            }
        }
    }
}