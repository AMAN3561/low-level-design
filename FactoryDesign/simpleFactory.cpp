#include<iostream>
using namespace std;

class Burger{
    public:
        virtual void prepare() = 0; // pure virtual function.
        virtual ~Burger(){} // virtual deconstructor.
};

class basicburger : public Burger{
    public:
        void prepare() override{
            cout<< "preparing basic burger with the bun, patty, & ketchup"<<endl;
        }
};

class standardburger : public Burger{
    public:
        void prepare() override{
            cout<< "preparing standard burger with the bun, patty, cheese,lettuce  & ketchup"<<endl;
        }
};

class premiumburger : public Burger{
    public:
        void prepare() override{
            cout<< "preparing premium burger with the premium bun, premium patty,premium cheese,premium lettuce  & premium ketchup"<<endl;
        }
};

class BurgerFactory{
public:
    Burger* createBurger(string type){
        if(type == "basic"){
            return new basicburger();
        }
        else if(type == "standard"){
            return new standardburger();
        }
        else if(type == "premium"){
            return new premiumburger();
        }
        else{
            cout<<"invalid burger type "<<endl;
            return nullptr;
        }
    }
};



int main(){
    string type = "standard";
    BurgerFactory* myBurgerFactory = new BurgerFactory();

    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();
    
    return 0;
}