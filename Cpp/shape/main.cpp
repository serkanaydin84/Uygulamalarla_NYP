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
    void draw() override {
        cout << "The triangle has been drawn. " << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "The rectangle has been drawn. " << endl;
    }
};

int main() {
    Triangle item1 = Triangle();
    item1.draw();

    char c = getchar();
    return 0;
}