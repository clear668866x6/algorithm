namespace SegmentTree01{
    int w[N];
    struct E{
        int l,r;
        int b,lb,rb,mb;
        int c,lc,rc,mc;
        int len,tag,rev;
    }tr[N<<2];
    
    void pushup(E& u,E l,E r){
        u.b=l.b+r.b;
        u.lb=l.c?l.lb:l.b+r.lb;
        u.rb=r.c?r.rb:r.b+l.rb;
        u.mb=max({l.mb,r.mb,l.rb+r.lb});
    
        
        u.c=l.c+r.c;
        u.lc=l.b?l.lc:l.c+r.lc;
        u.rc=r.b?r.rc:r.c+l.rc;
        u.mc=max({l.mc,r.mc,l.rc+r.lc});
    }
    
    void eval(int u,int opt){
        if(opt==0){
            tr[u].b=tr[u].lb=tr[u].rb=tr[u].mb=0;
            tr[u].c=tr[u].lc=tr[u].rc=tr[u].mc=tr[u].len;
            tr[u].tag=0,tr[u].rev=0;
        }else if(opt==1){
            tr[u].b=tr[u].lb=tr[u].rb=tr[u].mb=tr[u].len;
            tr[u].c=tr[u].lc=tr[u].rc=tr[u].mc=0;
            tr[u].tag=1,tr[u].rev=0;
        }else{
            swap(tr[u].b,tr[u].c);
            swap(tr[u].lb,tr[u].lc);
            swap(tr[u].rb,tr[u].rc);
            swap(tr[u].mb,tr[u].mc);
            tr[u].rev^=1;
        }
    }
    
    void pushdown(int u){
        if(tr[u].tag==0){
            eval(u<<1,0),eval(u<<1|1,0);
        }else if(tr[u].tag==1){
            eval(u<<1,1),eval(u<<1|1,1);
        }
        if(tr[u].rev){
            eval(u<<1,2),eval(u<<1|1,2);
        }
        tr[u].tag=-1,tr[u].rev=0;
    }
    
    void build(int u,int l,int r){
        int t=w[l];
        tr[u]={l,r,t,t,t,t,t^1,t^1,t^1,t^1,r-l+1,-1,0};
        if(l==r)return;
    
        int mid=l+r>>1;
    
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(tr[u],tr[u<<1],tr[u<<1|1]);
    }
    
    void modify(int u,int l,int r,int x){
        if(tr[u].l>r||tr[u].r<l)return;
        if(tr[u].l>=l&&tr[u].r<=r){
            eval(u,x);
            return;
        }
    
        pushdown(u);
        modify(u<<1,l,r,x);
        modify(u<<1|1,l,r,x);
        pushup(tr[u],tr[u<<1],tr[u<<1|1]);
    }
    
    E query(int u,int l,int r){
        if(tr[u].l>r||tr[u].r<l)return {};
        if(tr[u].l>=l&&tr[u].r<=r){
            return tr[u];
        }
    
        pushdown(u);
        E res;
        pushup(res,query(u<<1,l,r),query(u<<1|1,l,r));
    
        return res;
    }

    void init(int n){
        build(1,1,n);
    }
}

/*
支持的操作
1. 全赋为0
2. 全赋为1
3. 反转01操作
4. 查询0和1的数量
5. 查询最长连续0的长度

*/