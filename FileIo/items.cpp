#include "items.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

// Item implementations

// Constructors
Item::Item(){
    value = 0;
    description = NULL;
}


// Reads item info from the file stream that was passed in. 
Item::Item(istream& in_file, char delim){
    char temp[10000];
    in_file >> value;
    in_file.ignore();
    in_file.get(temp,9999,delim);
    description = new char[strlen(temp)+1];
}


// Initializes an item 
Item::Item(int value, char* description){
    this->value = value;
    this->description = new char[strlen(description)+1];
    strcpy(this->description,description);
}


// Copy Constructor
Item::Item(const Item & to_copy){
    this->copy(to_copy);
}


// Destructor
Item::~Item(){
    value = 0;
    delete[] description;
    description = NULL;
}


// Copies the arg passed in into the instance of the item.
void Item::copy(const Item& to_copy){
    value = to_copy.value;
    if(description)
        delete [] description;
    description = new char[strlen(to_copy.description)+1];
    strcpy(description,to_copy.description);
}


// Display function
void Item::display(){
    cout << "Item Value: " << value << endl
         <<"Description: " << description<< endl; 
}


// Writes an Item to the file stream passed in second argument is the terminating character for the write.
void Item::write_out(ofstream& fileOut, char term_char){
    fileOut << value << ':' << description << term_char;
}


//Weapons implementations


// Base constructor
Weapon::Weapon():Item(){
    attack_description = NULL;
}


// Argumented constructor
Weapon::Weapon(int weapon_value, char* weapon_description, int weapon_damage, char* attack_description):Item(weapon_value,weapon_description){
    this->attack_description = new char[strlen(attack_description)+1];
    strcpy(this->attack_description, attack_description);
    this->damage = weapon_damage;
}


// Copy constructor
Weapon::Weapon(const Weapon& to_copy){
    copy(to_copy);
}


// Destructor
Weapon::~Weapon(){
    delete[] attack_description;
    attack_description = NULL;
}


// Copies the argument passed in into the current instance of the weapon.
void Weapon::copy(const Weapon & to_copy){
    Item::copy(to_copy);
    attack_description = new char[strlen(to_copy.attack_description) + 1];
    strcpy(attack_description, to_copy.attack_description);
    damage = to_copy.damage;
}


// Display function
void Weapon::display(){
    Item::display();
    cout << "Attack Description: " << attack_description << endl
         << "Damage: " << damage << endl;
}


// Writes a weapon out to file. Second arg is the terminating character use for the write.
void Weapon::write_out(ofstream& fileOut, char term_char){
    Item::write_out(fileOut, ':');
    fileOut << attack_description << ':' << damage << term_char;
}
