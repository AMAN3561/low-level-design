#include<iostream>
using namespace std;

// subsystems :
class PowerSupply{
public:
    void powerprovider(){
        cout<<"power supply: providing power..."<<endl;
    }
};

class coolingsystem{
public:
    void cooiling(){
        cout<<"Cooling sytem : Fans started..."<<endl;
    }
};

class CPU{
public:
    void cpu(){
        cout<< "CPu system : CPU is starting..."<<endl;
    }
};

class Memory{
public:
    void memory(){
        cout<<"Memory: self test passed..."<<endl;
    }
};


class HardDrive{
public:
    void spinup(){
        cout<<"hard drive : Spinning up...."<<endl;
    }
};


class BIOS{
public: 
    void boot(CPU& c, Memory& m){
        cout<<"BIOS: booting CPU and memory checks..."<<endl;
        c.cpu();
        m.memory();
    }
};

class OperatingSystem{
public:
    void load(){
        cout<<"Operating System: Loading into system..."<<endl;
    }
};


// Fascade:
class Facade{
private:
    PowerSupply powersupply;
    coolingsystem cs;
    CPU c;
    Memory m;
    HardDrive HD;
    BIOS b;
    OperatingSystem os;

public:
    void startComputer(){
        cout<<"-------Computer is Starting-------"<<endl;
        powersupply.powerprovider();
        cs.cooiling();
        c.cpu();
        m.memory();
        b.boot(c, m);
        HD.spinup();
        os.load();
        cout<<"------Computer Booted Successfully-------"<<endl;
    }
};

int main(){
    Facade facade;
    facade.startComputer();

    return 0;
}