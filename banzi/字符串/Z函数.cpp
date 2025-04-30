namespace exKMP{
    int z[N];//以i开头的后缀和整个字符串前缀匹配的最长长度。
    string s;
    int n;

    void work(){
        int l=0,r=0;
        z[1]=n;

        FOR(i,2,n){
            if(i<=r)z[i]=min(z[i-l+1],r-i+1);
            while(s[1+z[i]]==s[i+z[i]])z[i]++;
            if(i+z[i]-1>r)l=i,r=i+z[i]-1;
        }
    }

    //Z函数求周期必须满足i+z[i]>n
}