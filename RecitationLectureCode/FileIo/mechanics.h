#ifndef MECHANICS_H
#define MECHANICS_H
// An attack for the game
// Attacks have a damage value, damage type and a description.
#include <iostream>
using namespace std;

class Attack
{
    public:
        // Constructors and Destructor
        Attack();
        Attack(int damage, int type, char* description);
        Attack(const Attack& to_copy);
        ~Attack();
        // called to use the attack returns the description and the args passed in are set to the values of the attack
        char* use_attack(int& type, int& damage);

        void write_out(ostream& out_file);
        void copy(Attack& to_copy);
    private:
        int attack_damage;
        int damage_type;
        char* attack_description;
};
#endif
