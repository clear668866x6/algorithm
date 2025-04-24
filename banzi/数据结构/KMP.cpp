namespace KMP{
    string a,b;//a为要匹配的（短的），b为匹配的（长的）
    int ne[N];

    void get_ne(){
        int j=0;
        FOR(i,2,n){
            while(j&&a[i]!=a[j+1])j=ne[j];
            if(a[i]==a[j+1])j++;
            ne[i]=j;
        }
    }

    void work(){
        n=a.sz,m=b.sz;

        a=' '+a,b=' '+b;

        get_ne();

        int j=0;
        FOR(i,1,m){
            while(j&&b[i]!=a[j+1])j=ne[j];
            if(a[j+1]==b[i])j++;
            if(j==n){
                //操作
                j=ne[j];
            }
        }
    }
}