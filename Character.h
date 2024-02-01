#pragma once
#include "Name.h"

class Character {
    // Character Attributes 
    Name name;
    float health = 100.0;
    float attack = 50.0;
    float magic = 50.0;

    // Meta Attributes 
    bool isBlocking = false;
    bool isParrying = false;
    bool isWarding = false;

public:
    // Character Actions 
    void Attack(Character& opponent);  // Attacking is easy to block against but hard to properly parry
    void Strike(Character& opponent);  // Striking is too awkward to block against but is easily parried
    void Magic(Character& opponent);   // Magic negates blocking and parrying but is weak to ward spells
    void EndDefense() { isBlocking = false; isParrying = false; isWarding = false; }

    void Block() { isBlocking = true; }
    void Parry() { isParrying = true; }
    void Ward() { isWarding = true; }

    // Set variables
    void setName(std::string _name) { name.setName(_name); }
    void setHealth(float _health) { health = _health; }
    void setAttack(float _attack) { attack = _attack; }
    void setMagic(float _magic) { magic = _magic; }

    // Get variables
    std::string getName() const { return name.getName(); }
    float getHealth() const { return health; }
    float getAttack() const { return attack; }
    float getMagic() const { return magic; }
    int getDefense() const;

    Character() {}
    Character(std::string _name) { setName(_name); }
};