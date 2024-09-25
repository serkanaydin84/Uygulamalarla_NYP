#include<iostream>
using std::string;
using std::cout;
using std::endl;

class Shape {
protected:
    int x;
    int y;

public:
    Shape(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void setX(int value) {
        x = value;
    }
    void setY(int value) {
        y = value;
    }
    virtual void draw() = 0;    // C++ da abstract sınıf tanımlama bu şekilde yapılıyor
};

class Triangle : public Shape {
public:
    Triangle(int x, int y) : Shape(x, y) {
        this->x = x;
        this->y = y;
    }
    void draw() override {
        cout << "The triangle (" << x << "-" << y << ") has been drawn. " << endl;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y) : Shape(x, y) {
        this->x = x;
        this->y = y;
    }
    void draw() override {
        cout << "The rectangle (" << x << "-" << y << ") has been drawn. " << endl;
    }
};

class Square : public Rectangle {
public:
    Square(int x) : Rectangle(x, x) {
        this->x = x;
    }
    void draw() override {
        cout << "The square (" << x << ") has been drawn. " << endl;
    }
};

int main() {
    Triangle item1 = Triangle(3, 5);
    Rectangle item2 = Rectangle(6, 8);
    Square item3 = Square(7);

    item1.draw();
    item2.draw();
    item3.draw();

    char c = getchar();
    return 0;
}