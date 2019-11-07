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


