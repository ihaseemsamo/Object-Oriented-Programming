#include <iostream>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon)
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks using " << weaponType << "!" << endl;
    }

    virtual void defend() {
        cout << name << " defends against the attack!" << endl;
    }

    virtual void displayStats() {
        cout << "Character: " << name << " | Level: " << level
             << " | HP: " << healthPoints << " | Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " performs a powerful melee attack dealing " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int spell)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}

    void defend() override {
        cout << name << " casts a magical barrier using " << manaPoints << " mana points!" << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, string weapon, int stealth, int agil)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agil) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << " | Agility: " << agility << endl;
    }
};

int main() {
    Warrior w(1, "Thor", 10, 100, "Sword", 50, 25);
    Mage m(2, "Merlin", 12, 80, "Staff", 100, 40);
    Archer a(3, "Legolas", 15, 90, "Bow", 30, 85);
    Rogue r(4, "Shadow", 11, 85, "Daggers", 70, 95);

    cout << "\n---- Character Actions ----\n";
    w.attack();
    m.defend();
    a.attack();
    r.displayStats();

    return 0;
}

