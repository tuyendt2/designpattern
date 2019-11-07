#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum E_SHAPETYPE{
   E_SHAPETYPE_RECT = 0 ,
   E_SHAPETYPE_SQUARE,
   E_SHAPETYPE_CIRCLE,
   E_SHAPETYPE_DEFAULT
};

class Shape {
public:
   virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    void draw() {
      cout << "Inside Rectangle::draw() method." << endl;
   }
};

class Square : public Shape {
public:
    void draw() {
      cout << "Inside Square::draw() method." << endl;
   }
};


class Circle : public Shape {
public:
    void draw() {
      cout << "Inside Circle::draw() method." << endl;
   }
};

void  Demo() {
// if we have list object want to create with dynamic decision so it will come into complex handling .
// vector<E_SHAPETYPE> listShapeType;

     vector<Shape*> list;

      Shape *shape1 = new Rectangle();

      list.push_back(shape1);

      Shape *shape2 = new Square();

      list.push_back(shape2);

      Shape *shape3 = new Circle();

      list.push_back(shape3);

      for (int i  = 0 ; i < list.size(); i++) list[i]->draw();

}


class ShapeFactory {

public:
    Shape* getShape(E_SHAPETYPE shapeType){
      if(shapeType == E_SHAPETYPE_DEFAULT){
         return NULL;
      }
      if(shapeType == E_SHAPETYPE_CIRCLE){
         return new Circle();

      } else if(shapeType == E_SHAPETYPE_RECT){
         return new Rectangle();

      } else if(shapeType == E_SHAPETYPE_SQUARE){
         return new Square();
      }

      return NULL;
   }
};


void FactoryPatternDemo() {

      ShapeFactory *shapeFactory = new ShapeFactory();

      vector<Shape*> list;

      Shape *shape1 = shapeFactory->getShape(E_SHAPETYPE_CIRCLE);

      list.push_back(shape1);

      Shape *shape2 = shapeFactory->getShape(E_SHAPETYPE_RECT);

      list.push_back(shape2);

      Shape *shape3 = shapeFactory->getShape(E_SHAPETYPE_SQUARE);

      list.push_back(shape3);

      for (int i  = 0 ; i < list.size(); i++) list[i]->draw();

}
