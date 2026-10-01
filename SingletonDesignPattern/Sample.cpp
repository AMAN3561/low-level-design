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
        if(instance == nullptr){
            instance = new Singletion();
        }
        return instance;
    }
};
Singletion* Singletion::instance = nullptr;

int main(){

    Singletion* s1 = Singletion::getInstance();
    Singletion* s2 = Singletion::getInstance();
    cout<<(s1 == s2) <<endl;
    return 0;
}