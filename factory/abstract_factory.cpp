#include <iostream>

class Shape
{
public:
    Shape(){
        id_ = total_++;
    }
    virtual void draw() = 0;

protected:
    int id_;
    static int total_;
};

class Circle : public Shape
{
public:
    void draw() {
        std::cout<<"circle: "<<id_<<" draw"<<std::endl;
    }

};

class Square: public Shape
{
public:
    void draw() {
        std::cout<<"square: "<<id_<<" draw"<<std::endl;
    }

};

class Ellipse: public Shape
{
public:
    void draw() {
        std::cout<<"ellipse: "<<id_<<" draw"<<std::endl;
    }
};

class Polygone: public Shape
{
public:
    void draw() {
        std::cout<<"polygone: "<<id_<<" draw"<<std::endl;
    }
};

class Factory
{
public:
    virtual Shape* createCurvedInstance()  = 0;
    virtual Shape* createStraignInstance() = 0;
};

class SimpleShapeFactory : public Factory
{
    public:
        Shape* createCurvedInstance(){
            return new Circle;
        }

        Shape* createStraignInstance(){
            return new Square;
        }
};

class ComplexShapeFactory: public Factory
{
    public:
        Shape* createCurvedInstance(){
            return new Ellipse;
        }

        Shape* createStraignInstance(){
            return new Polygone;
        }
};

int Shape::total_ = 0;

#define COMPLEX
int main(int argc, const char *argv[])
{
#ifdef SIMPLE
    Factory* factory = new SimpleShapeFactory;
#elif defined COMPLEX
    Factory* factory = new ComplexShapeFactory;
#endif

    Shape* shapes[3];

    shapes[0] = factory->createCurvedInstance();
    shapes[1] = factory->createStraignInstance();
    shapes[2] = factory->createCurvedInstance();

    for(int i = 0;i < 3; i++) {
        shapes[i]->draw();
    }

    return 0;
}
