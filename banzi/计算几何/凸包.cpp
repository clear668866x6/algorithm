namespace hull{
    int n;
    struct E{
        int x,y;
        bool operator<(const E& t)const{
            if(x==t.x)return y<t.y;
            return x<t.x;
        }
    }w[N];
    vector<E>hull;
    
    bool convex(E a,E b,E c){
        return (c.x-b.x)*(b.y-a.y)>(c.y-b.y)*(b.x-a.x);
        //yb-ya/xb-xa>yc-yb/xc-xb
    }
    
    void add(E a){
        while(hull.sz>1&&convex(hull.end()[-2],hull.back(),a)){
            hull.pop_back();
        }
        hull.pb(a);
    }
}