template<class T>
struct Point{
    T x,y;

    Point operator+(const Point& t)const{
        return {x+t.x,y+t.y};
    }

    Point operator-(const Point& t)const{
        return {x-t.x,y-t.y};
    }

    T operator*(const Point& t)const{
        return t.x*x+t.y*y;
    }

    T operator&(const Point& t)const{
        return x*t.y-y*t.x;
    }

    T operator/(T t){
        return {x/t,y/t};
    }

    T operator*(T t){
        return {x*t,y*t};
    }

    T getlen(){
        return sqrt(x*x+y*y);
    }

    /* 线段*/

    Point rotate(Point a,T angle){
        return {a.x*cos(angle)+a.y*sin(angle),-a.x*sin(angle)+a.y*cos(angle)};
    }

    bool get_line_intersaction(Point p,Point v,Point q,Point w){
        Point u=p-q;
        T t=(w&u)/(v&w);
        return p+v*t;
    }

}