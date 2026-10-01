#include<iostream>
using namespace std;

// singleton Design Pattern
class Singletion{
private: // Doing private 
    static Singletion* instance;

    Singletion(){
        cout<< "Singletion Constructor is called, New object created"<< endl;
    }

public:
    static Singletion* getInstance(){
        return instance;  
    }
};
Singletion* Singletion::instance = new Singletion(); // Eager initialization, wastes memory when method is not used.


int main(){

    Singletion* s1 = Singletion::getInstance();
    Singletion* s2 = Singletion::getInstance();
    Singletion* s3 = Singletion::getInstance();
    Singletion* s4 = Singletion::getInstance();
    Singletion* s5 = Singletion::getInstance();
    
    cout<<(s1 == s2) <<endl;
    return 0;
}