#include <iostream>
using namespace std; 

class Vector2D{
    public:
        int x;
        int y;
        void SetX(int x);
        void SetY(int y);
        int GetX();
        int GetY();
        Vector2D();
        Vector2D(int x, int y);
};

int operator*(const Vector2D& v1,const Vector2D& v2 ){
    return (v1.x * v2.x) +(v1.y * v1.y);
}

int main(){
    Vector2D v1(45,98), v2(8,156), v3(143,8), v4(216,0);
    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()<< "," << v2.GetY() << ") = " << v1*v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX()<< "," << v3.GetY() << ") = " << v2*v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX()<< "," << v4.GetY() << ") = " << v3*v4 << endl;
    
    return 0;

}

Vector2D::Vector2D(){
    x = 0;
    y = 0;

}
Vector2D::Vector2D(int X,int Y){
    x = X;
    y = Y;
}

void Vector2D::SetX(int x){
    this->x = x;

}
void Vector2D::SetY(int y){
    this->y = y;

}
int Vector2D::GetX(){
    return x;

}
int Vector2D::GetY(){
    return y;

}

