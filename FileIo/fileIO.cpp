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

// Consts and input vars.
const int INPUT_SIZE = 301;
const int ARRAY_SIZE = 10;
char INPUT[INPUT_SIZE];
char INPUT2[INPUT_SIZE];
const char FILE_NAME[] = "file_io.txt";

// Functions used to read and write to file.
void read_from_file(Item** dest,int& count);
Item get_Item_info();
Weapon get_Weapon_info();
void write_to_file(Item& to_write, char type, ofstream& fout);



int main()
{
    ofstream fout;
    ifstream fin;
    fout.open(FILE_NAME, ios::app);
    int current_num = 0;
    Item* items[ARRAY_SIZE];
    bool done = false;
    char user_input;

    cout << "This is the File IO demo program.\n"
         << "We will generate several different data elements and then store them in a file.\n"
         << "You will write the code to read the items back out from the file." << endl;

    do {
        cout << "Enter '1' to make an item.\n"
            << "Enter '2' to make a weapon.\n"
            << "Input: ";
        cin >> user_input;
        cin.ignore(INPUT_SIZE,'\n');
        switch (user_input) {
            case '1':{
                Item temp_item(get_Item_info());
                write_to_file(temp_item, user_input, fout);
                break;
                     }
            case '2': {
                Weapon temp_weapon(get_Weapon_info());
                write_to_file(temp_weapon, user_input, fout);
                break;
                      }
            default:
                done = true;
                break;
        }

    }while(!done);
    fout.clear();
    fout.close();


    // Place code to read from file here.

    return 0;
}


// Implement the function to read from file and display the info for each element in the file.
void read_from_file(Item** dest,int& count){

    return;
}


// Writes an the type of an item out to file as well as the rest of the info for the item or weapon.
void write_to_file(Item& to_write, char type, ofstream& fout){
    fout << type << ':';
    to_write.write_out(fout, '\n');
}



// Prompts for info about an item and returns the item created.
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


// Prompts for info about a weapon and returns the weapon created.
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
