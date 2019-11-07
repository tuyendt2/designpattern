#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    Base(string name){
        this->name = name;
    }
    string getInfo(){
       return "Base class : getInfo";
    }
    virtual string getName(){
        return "Base class : " + name ;
    }
protected:
    string name;
};


class Derived : public Base {
public:
    Derived(string name):Base(name){}
    string getInfo(){ // override
        return "Derived class : getInfo";
    }
    string getName(){
        return "Derived class" + name ;
    }
};

void virtualAbstractMethodExample(){
    // virtual abstract method
   Base *base = new Base("BaseClassName");
   cout << base->getInfo() << endl;
   cout << base->getName() << endl;
   // what is expected ?
   //delete base;
   base = new Derived("DerivedClassName");
   cout << base->getInfo() << endl;
   cout << base->getName() << endl;

   Derived *derived = new Derived("DerivedClassName");
   cout << derived->getInfo() << endl;
   cout << derived->getName() << endl;

   Base *castBase = dynamic_cast<Base*>(derived);
   // what happen ?
   cout << castBase->getInfo() << endl;
   cout << castBase->getName() << endl;
   //delete castBase;
}


