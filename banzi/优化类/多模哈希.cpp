
namespace mutihash{
    constexpr int MOD0=998244353;
    constexpr int MOD1=1000000007;
    constexpr int MOD2=1000000009;
    
    struct MOD{
        int x0,x1,x2;
        MOD():x0(0),x1(0),x2(0){}
        MOD(int x0,int x1,int x2):x0(x0),x1(x1),x2(x2){}
    };
    
    MOD operator+(const MOD& a,const MOD& b){
        return {(a.x0+b.x0)%MOD0,(a.x1+b.x1)%MOD1,(a.x2+b.x2)%MOD2};
    }
    
    MOD operator-(const MOD& a,const MOD& b){
        return {(a.x0-b.x0+MOD0)%MOD0,(a.x1-b.x1+MOD1)%MOD1,(a.x2-b.x2+MOD2)%MOD2};
    }
    
    MOD operator*(const MOD& a,const MOD& b){
        return {(a.x0*b.x0)%MOD0,(a.x1*b.x1)%MOD1,(a.x2*b.x2)%MOD2};
    }
    
    bool operator==(const MOD& a,const MOD& b){
        return a.x0==b.x0&&a.x1==b.x1&&a.x2==b.x2;
    }

}
