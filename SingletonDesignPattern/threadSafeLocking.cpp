#include<iostream>
using namespace std;

// singleton Design Pattern
class Singletion{
private: // Doing private 
    static Singletion* instance;
    static mutex mtx;

    Singletion(){
        cout<< "Singletion Constructor is called, New object created"<< endl;
    }

public:
    static Singletion* getInstance(){
        if(instance == nullptr){
            lock_guard<mutex> lock(mtx);// lock for thread saftey.
            if(instance == nullptr){
                instance = new Singletion();
            }     
        }
        return instance;
    }
};
Singletion* Singletion::instance = nullptr;
mutex Singletion::mtx;

int main(){

    Singletion* s1 = Singletion::getInstance();
    Singletion* s2 = Singletion::getInstance();
    cout<<(s1 == s2) <<endl;
    return 0;
}