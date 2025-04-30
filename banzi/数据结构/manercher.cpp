namespace manacher{
    char s[N],a[N];
    int p[N],n,m;

    void init(){
        m=0;
        s[m++]='$',s[m++]='#';
        FOR(i,0,n-1)s[m++]=a[i],s[m++]='#';
        s[m++]='^';
        n=m;
    }

    void work(){
        int mr=0,mid;

        FOR(i,0,n-1){
            if(i<mr)p[i]=min(p[mid*2-i],mr-i);
            else p[i]=1;
            while(s[i-p[i]]==s[i+p[i]])p[i]++;
            if(i+p[i]>mr){
                mr=i+p[i];
                mid=i;
            }
        }
    }
}