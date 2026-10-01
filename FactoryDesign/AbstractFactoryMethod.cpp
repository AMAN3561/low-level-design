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

class GarlicBread{
public:
    virtual void prepare() = 0;
};

class basicGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing basic GarlicBread with butter and garlic\n";
    }
};

class cheeseGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing cheese GarlicBread with butter and garlic\n";
    }
};

class basicwheatGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing basicwheat GarlicBread with butter and garlic\n";
    }
};

class cheeesewheatGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"Preparing cheesewheat GarlicBread with butter and garlic\n";
    }
};

class MealFactory{
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghBurger : public MealFactory{
public:
    Burger* createBurger(string& burgertype) override{
        if(burgertype == "basic"){
            return new basicburger();
        }
        else if(burgertype == "standard"){
            return new standardburger();
        }
        else if(burgertype == "premium"){
            return new premiumburger();
        }
        else{
            cout<<"invalid burger type "<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& GarlicBreadtype) override{
        if(GarlicBreadtype == "basic"){
            return new basicGarlicBread();
        }
        else if(GarlicBreadtype == "cheese"){
            return new cheeseGarlicBread();
        }
        else if(GarlicBreadtype == "basiccheese"){
            return new basicwheatGarlicBread();
        }
        else if(GarlicBreadtype == "cheesewheat"){
            return new cheeesewheatGarlicBread();
        }
        else{
            cout<<"invalid burger type "<<endl;
            return nullptr;
        }
    }

};

class KingBurger : public MealFactory{
public:
    Burger* createBurger(string& burgertype) override{
        if(burgertype == "basic"){
            return new Basicwheatburger();
        }
        else if(burgertype == "standard"){
            return new standardwheatburger();
        }
        else if(burgertype == "premium"){
            return new premiumwheatburger();
        }
        else{
            cout<<"invalid burger type "<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& GarlicBreadtype) override{
        if(GarlicBreadtype == "basic"){
            return new basicGarlicBread();
        }
        else if(GarlicBreadtype == "cheese"){
            return new cheeseGarlicBread();
        }
        else if(GarlicBreadtype == "basiccheese"){
            return new basicwheatGarlicBread();
        }
        else if(GarlicBreadtype == "cheesewheat"){
            return new cheeesewheatGarlicBread();
        }
        else{
            cout<<"invalid burger type "<<endl;
            return nullptr;
        }
    }
};



int main(){
    string burgertype = "standard";
    string GarlicBreadtype = "cheesewheat";


    MealFactory* mealfactory = new KingBurger();

        Burger* burger = mealfactory->createBurger(burgertype);
        GarlicBread* garlicbread = mealfactory->createGarlicBread(GarlicBreadtype);

        burger->prepare();
        garlicbread->prepare();


    return 0;
}