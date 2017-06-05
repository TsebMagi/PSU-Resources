//Doug Whitley
//FileIO Program
//PSU Spring 2017

// Expected Format of input
// Leading int determines if the entry is of type 'Item' or type 'Weapon'
// 1 = Item
// 2 = Weapon
// Items have an integer 'value' and a char[] 'description' the delimeter between these values is a ':' character and the entry ends with a '\n'
// Weapons have the information of an Item followed by a char[] 'attack_description' and an int 'damage' the delimeter between the Item data
// and the Weapon data is ':' each of the Weapon data elements is also seperated by a ':' and the enry is terminated by a '\n'


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "items.h"
using namespace std;

const int INPUT_SIZE = 301;
char INPUT[INPUT_SIZE];
char INPUT2[INPUT_SIZE];


Item get_Item_info();
Weapon get_Weapon_info();

const char FILE_NAME[] = "file_io.txt";

int main()
{
    ofstream fout;
    ifstream fin;
    fout.open(FILE_NAME, ios::app);
    int current_num = 0;
    Item items[10];

    Item temp_item(get_Item_info());
    Weapon temp_weapon(get_Weapon_info());

    temp_item.display();
    cout << endl;
    temp_weapon.display();
    fout << '1' << ':';
    temp_item.write_out(fout, '\n');
    fout << '2' << ':';
    temp_weapon.write_out(fout, '\n');

    fout.clear();
    fout.close();
    return 0;
}

Item get_Item_info(){
    int value;
    cout << "Enter integer value of item: ";
    cin >> value;
    cin.ignore();
    cout << "Enter item description: ";
    cin.get(INPUT, INPUT_SIZE -1, '\n'); 
    cin.ignore(INPUT_SIZE, '\n');
    return Item(value, INPUT);
}


Weapon get_Weapon_info(){
    int value;
    int damage;
    cout << "Enter value of weapon: ";
    cin >> value;
    cin.ignore();
    cout << "Enter description of weapon: ";
    cin.get(INPUT, INPUT_SIZE - 1, '\n');
    cin.ignore(INPUT_SIZE, '\n');
    cout << "Enter weapon damage: ";
    cin >> damage;
    cin.ignore();
    cout << "Enter attack description: ";
    cin.get(INPUT2, INPUT_SIZE - 1, '\n');
    cin.ignore(INPUT_SIZE, '\n');
    return Weapon(value, INPUT, damage, INPUT2);
}
