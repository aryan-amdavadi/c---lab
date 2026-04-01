#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(){
        x=0;
        y=0;
    }
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
    Point& move(int a, int b){
        x = x + a;
        y = y + b;
        return *this;
    }
    void disp(){
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    }
};

void movePoint(Point* p, int dx, int dy) {
    p->move(dx, dy);
}

int main(){
    Point p(1,1);
    p.disp();
    p.move(10, 10).move(10, 10);
    p.disp();

    Point p2(5,5);
    p2.disp();
    movePoint(&p2, 2, 3);
    p2.disp();
}