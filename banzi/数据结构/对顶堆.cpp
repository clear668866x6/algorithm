namespace duidingdui{
    multiset<int>l,r;
    int ls=0,rs=0;

    void balance(){
        while(l.sz>r.sz+1){
            r.insert(*l.rbegin());
            rs+=*l.rbegin();
            ls-=*l.rbegin();
            l.erase(prev(l.end()));
        }

        while(l.sz<r.sz){
            l.insert(*r.begin());
            ls+=*r.begin();
            rs-=*r.begin();
            r.erase(r.begin());
        }
    }

    void add(int x){
        if(!l.sz||*l.rbegin()>=x){
            l.insert(x);
            ls+=x;
        }else{
            r.insert(x);
            rs+=x;
        }
        balance();
    }

    void remo(int x){
        if(l.count(x)){
            l.erase(l.find(x));
            ls-=x;
        }else{
            r.erase(r.find(x));
            rs-=x;
        }
        balance();
    }

    int mid(){
        return *l.rbegin();
    }

    int get(){
        return (mid()*(l.sz)-ls+(rs-mid()*(r.sz)));
    }
}