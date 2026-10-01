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

class Basicwheatburger : public Burger{
public:
    void prepare() override{
        cout<<"preparing basic wheat bun\npatty\ncheese";
    }
};

class standardwheatburger : public Burger{
public:
    void prepare() override{
        cout<<"preparing standard wheat bun\npatty\ncheese";
    }
};

class premiumwheatburger : public Burger{
public:
    void prepare() override{
        cout<<"preparing premium wheat bun\npatty\ncheese\nlettuce";
    }
};

class BurgerFactory{
public:
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurger : public BurgerFactory{
public:
    Burger* createBurger(string& type) override{
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

class KingBurger : public BurgerFactory{
public:
    Burger* createBurger(string& type) override{
        if(type == "basic"){
            return new Basicwheatburger();
        }
        else if(type == "standard"){
            return new standardwheatburger();
        }
        else if(type == "premium"){
            return new premiumwheatburger();
        }
        else{
            cout<<"invalid burger type "<<endl;
            return nullptr;
        }
    }
};



int main(){
    string type = "standard";

    BurgerFactory* myFactory = new KingBurger();
    Burger* burger = myFactory->createBurger(type);

    burger->prepare();
 
    
    return 0;
}