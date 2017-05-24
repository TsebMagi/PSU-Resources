#include "items.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

//Item implementations

Item::Item(){
    value = 0;
    description = NULL;
}


Item::Item(istream& in_file, char delim){
    char temp[10000];
    in_file >> value;
    in_file.ignore();
    in_file.get(temp,9999,delim);
    description = new char[strlen(temp)+1];
}


Item::Item(int value, char* description){
    this->value = value;
    this->description = new char[strlen(description)+1];
    strcpy(this->description,description);
}


Item::Item(const Item * to_copy){
    this->copy(to_copy);
}


Item::~Item(){
    value = 0;
    delete[] description;
}


void Item::copy(const Item& to_copy){
    value = to_copy.value;
    if(description)
        delete [] description;
    description = new char[strlen(to_copy.description)+1];
    strcpy(description,to_copy.description);
}


void Item::display(){
    cout << "Item Value: " << value << "Description: " << description<< endl; 
}


void Item::write_out(ofstream& fileOut, char delim){
    fileOut << value << ':' << description << delim;
}


//Weapons implementations
Weapon::Weapon():Item(){
    attacks = NULL;
}


Weapon::Weapon(int weapon_value, char* weapon_description, Attack* attacks_vector, int vector_size):Item(weapon_value,weapon_description){
    num_attacks = vector_size;
    attacks = new Attack[num_attacks];
    for(int i = 0; i < num_attacks; ++i)
        attacks[i].copy(attacks_vector[i]);
}


Weapon::Weapon(int weapon_value, char* weapon_description, int weapon_damage, int damage_type, char* attack_description):Item(weapon_damage,weapon_description){
    num_attacks = 1;
    attacks = new AttackAttack(weapon_damage,damage_type,attack_description);
}


Weapon::Weapon(const Weapon& to_copy){
    copy(to_copy);
}


Weapon::~Weapon(){
    delete[] attacks;
}


void Weapon::copy(Weapon & to_copy){}


void Weapon::display(){}


void Weapon::write_out(ofstream& fileOut, char delim){}
