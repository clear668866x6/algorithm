
int n;
struct E{
    int x,y;
    E operator-(const E& t)const{
        return {x-t.x,y-t.y};
    }
}w[N];

int cross(E a,E b){
    return a.x*b.y-a.y*b.x;
}

int area(){
    int ans=0;

    FOR(i,2,n-1){
        ans+=cross(w[i]-w[1],w[i+1]-w[i]);
    }
    return abs(ans);
}

void solve() {
    cin>>n;

    FOR(i,1,n)cin>>w[i].x>>w[i].y;

    int cnt=0;

    FOR(i,2,n){
        cnt+=__gcd(abs(w[i].x-w[i-1].x),abs(w[i].y-w[i-1].y));
    }
    cnt+=__gcd(abs(w[n].x-w[1].x),abs(w[n].y-w[1].y));

    int a=(area()-cnt+2)/2;

    cout<<a<<' '<<cnt<<endl;
}