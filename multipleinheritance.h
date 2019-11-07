#include "string"
#include <iostream>
using namespace std;

class Parent{

    virtual void run() = 0 ;

};

class FirstChild: public Parent{
public:
    void run(){
        cout << "FirstChild run" << endl;
    }

    void doFirst(){
       cout << "FirstChild do" << endl;
    }
};

class SecondChild: public Parent{
public:
    void run(){
     cout << "SecondChild run" << endl;
    }

    void doSecond(){
       cout << "SecondChild do" << endl;
    }
};

class GrandChild: public FirstChild, public SecondChild{
public :
    GrandChild(){}
    void doNothing(){}
};

void TestMultipleInheritance(){
      GrandChild grandChild;
      grandChild.doFirst();
      grandChild.doSecond();
      //grandChild.run();
}






