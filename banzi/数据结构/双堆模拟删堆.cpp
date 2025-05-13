struct E{//双 priority_queue 模拟可删堆
    priority_queue<int,VI,greater<int>>q1,q2;

    void clear(){
        while(q1.sz)q1.pop();
        while(q2.sz)q2.pop();
    }

    bool empty(){
        return !(q1.sz-q2.sz);
    }

    void push(int x){
        q1.push(x);
    }

    void pop(int x){
        q2.push(x);
    }

    int top(){
        while(q1.sz&&q2.sz&&q1.top()==q2.top()){
            q1.pop(),q2.pop();
        }
        return q1.top();
    }
};