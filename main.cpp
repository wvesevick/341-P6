#include <iostream>
using namespace std;

#include "hashtable.h"
#include "hashTableLinearProbing.h"
#include "hashTableChaining.h"
#include "hashTableCuckoo.h"
//Type git add *.cpp *.h *.txt *.inl makefile and hit enter.
//Type git commit -m "finished phase(s) X"
//Type git push origin master and hit enter.

/*
CHECKLIST
blah | tee input1.txt
// all .h .cpp
// makefile
// valgrind output
// tee command
// submit files used for load operations
*/

//MAIN NOTES
// First Insert Does Not Work for Linear, is it main or is it in linear hash table
// Ask how to make the table in main so you dont have to hardcode hwatever version is being tested
// Ask about the difference between n and m0
//

int main (){

    HashTable * theTable;

    int user = 10;
    cout << "Welcome to the Anglo-Saxon Castle" << endl
    << "1) Linear Probing" << endl << "2) Separate Chaining" << endl
    << "3) Cuckoo Hashing" << endl << "0) Quit" << endl
    << "Please Enter Your Choice:" << endl
    << "*************************" << endl;
    cin >> user;

    if (user == 0){
        cout << "QUITTING" << endl;
        return 0;
    } else if (user == 1){ // LINEAR PROBING
        cout << "You have selected Linear Probing" << endl;
        theTable = new HashTableLinearProbing();

    } else if (user == 2){ // SEPARATE CHAINING
        cout << "You have selected Separate Chaining" << endl;
        theTable = new HashTableChaining();
        
    } else if (user == 3){ // CUCKOO HASHING
        cout << "You have selected Cuckoo Hashing" << endl;
        theTable = new HashTableCuckoo();

    } else {
        cout << "NO TABLE SELECTED" << endl;
    }

    int command = 10;
    int num;
    while(command != 0){
        // start whatever hashtable gets called
        cout << "1) Load Table From File" << endl << "2) Insert" << endl
        << "3) Search" << endl << "4) Delete" << endl
        << "5) Print Hash Table" << endl << "0) Quit" << endl;
        cin >> command;
        if(command == 1){
            cout << "LOADING TABLE FROM FILE" << endl;
            string fileName;
            cout << "What File Would You Like to Load?" << endl;
            cin >> fileName;
            theTable->load(fileName);
            // load table function

        } else if (command == 2){
            cout << "You have selected insert" << endl;
            cout << "What number would you like to insert" << endl;
            cin >> num;
            theTable->insert(num);

        } else if (command == 3){
            cout << "What number would you like to search for" << endl;
            cin >> num;
            theTable->search(num);
            //search number
        } else if (command == 4){
            cout << "What number would you like to delete" << endl;
            cin >> num;
            theTable->remove(num);
            //delete number
        } else if (command == 5){
            cout << "PRINTING HASH TABLE" << endl;
            theTable->print();
            // print function
        } else if (command == 0){
            cout << "Quiting Program" << endl;
        } else {
            cout << "Invalid Input" << endl;
        }


    }

    delete theTable;
    return 0;
}
