// Doug Whitley
// File IO Program
// PSU Spring 17
#ifndef GAME_H
#define GAME_H //game.h
#include "mechanics.h"
#include "items.h"



// The Character class is used in the game as a base class for most entities that the player might interact with.
// The Character has a level, name, and description.
class Character
{
    public:
        
        Character();
        Character(char* name, char* description,int level = 1);
        Character(const Character&);

        ~Character();

        void display();

    private:
        int level;
        char* name;
        char* description;
};


// The Monster class is used in the game to represent a type of adversary that the player might encounter.
// Monsters are Characters and have attacks and loot.
class Monster: public Character
{
    public:
        // Constructors and Destructor
        Monster();
        Monster(char* monster_name, char* monster_description, int monster_level, Attack* monster_attacks, Item monster_loot);
        Monster(Character monster_character, Attack monster_attack, Item monster_loot);
        Monster(const Monster& to_copy);
        ~Monster();

        void display();
    private:
        Attack* attacks;
        Item loot;
};


// The Villain class is used in the game to represent particularly powerful monsters
// Villains have a monologue
class Villain: public Monster
{
    public:
        // Constructors and Destructor
        Villain();
        ~Villain();

    private:
};
#endif //game.h
