#include<iostream>
#include<string>
using namespace std;

// component Interface : defines a common interface for MArio and all powe-up decotators

class Character{
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {} // virtual destructor .
};

// concerete Component : Basic Mario character with no power-ups
class Mario : public Character{
public:
    string getAbilities() const override{
        return "Mario";
    }
};

// Abstract Decorattor : characterDedorator "is-a" charracter and "has-a" character.
class CharacterDecorator : public Character{
protected:
    Character* character; // wrapped component.

public:
    CharacterDecorator(Character* c){
        this->character = c;
    }
};

class Heightup : public CharacterDecorator{
public:
    Heightup(Character* c) : CharacterDecorator(c){ }

    string getAbilities() const override{
        return character->getAbilities() + "with Heightup";
    }
};

class GunPowerUP : public CharacterDecorator{
public:
    GunPowerUP(Character* c) : CharacterDecorator(c){ }

    string getAbilities() const override{
        return character->getAbilities() + "with GunPowerUP";
    }
};

// concrete Decorator : star power-up {temporary ability}

class StarpowerUp : public CharacterDecorator{
public:
    StarpowerUp(Character* c) : CharacterDecorator(c){ }

    string getAbilities() const override{
        return character->getAbilities() + "with star power-up(limited time)";
    }

    ~StarpowerUp(){
        cout<<"Destroying startpowerup decorator";
    }
};

int main(){

    // create a basic mario character :
    Character* mario = new Mario();
    cout<<"Basic character:" << mario->getAbilities()<<endl;

    // Decorate Mario with a Heightup powerup:
    mario = new Heightup(mario);
    cout<<"after heightup"<< mario->getAbilities()<<endl;

    // Decorate Mario with a GunPowerUp powerup:
    mario = new GunPowerUP(mario);
    cout<<"after GunPowerUP"<< mario->getAbilities()<<endl;

    // Decorate Mario with a starPowerUp powerup:
    mario = new StarpowerUp(mario);
    cout<<"after StarpowerUp"<< mario->getAbilities()<<endl;

    delete mario;

    return 0;

}