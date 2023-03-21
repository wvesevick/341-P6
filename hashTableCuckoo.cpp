#include "hashTableLinearProbing.h"
#include "hashTableCuckoo.h"
#include "hashtable.h"

#include <cmath>

HashTableCuckoo::HashTableCuckoo(){ // hash function is x % n
    cout << "How large would you like the table" << endl;
    cin >> n;
    m = n/2;
    int newTable[n];
    table = newTable;
    ifstream loadFile ("loadfile.txt");
    for(int x = 0; x < n; x++){
        table[x] = 0;
    }
    int * table1 = &table[0]; // hash function is x % m
    int * table2 = &table[m]; // has function is floor(value/m) % m
}

HashTableCuckoo::~HashTableCuckoo(){

}

int HashTableCuckoo::insert(int value){
    int temp;
    int max_loops = 2;

    for (int x=0; x<max_loops; x++){
        if((table1 + (value%m)) == 0){
            table1 = table1+(value%m);
            table1 = &value;
            return 1;
        } else {
            temp = table1[value%m];
            table1[value%m] = value;
            value = temp;
        }
        
        if(table2 + ((int)floor(value/m) % m)== 0){
            table2 = table2 + ((int)floor(value/m) % m);
            table2 = &value;
            return 1; 

        } else {
            temp = table2[((int)floor(value/m) % m)];
            table2[((int)floor(value/m) % m)] = value;
            value = temp;
        }
    }
    cout << "FAILED INSERTION" << endl;
    return 0;

}

int HashTableCuckoo::search(int value){
    int temp;
    int max_loops = 2;

    for (int x=0; x<max_loops; x++){
        if((table1 + (value%m)) == 0){
            //means nothing is there
            return 0;
        } else if ((table1[value%n] == value)){
            return 1;
        }
        
        if(table2 + ((int)floor(value/m) % m)== 0){
            //means nothing is there
            return 0;
        } else if (table2 + ((int)floor(value/m) % m)== 0){
            return 1;
        }
    }

    cout << "NOT FOUND" << endl;

    return 0;
}

int HashTableCuckoo::remove(int value){
   int temp;
    int max_loops = 2;

    for (int x=0; x<max_loops; x++){
        if((table1 + (value%m)) == 0){
            //means nothing is there
            return 0;
        } else if ((table1[value%n] == value)){
            table1[value&n] = 0;
            cout << "REMOVED VALUE" << endl;
            return 1;
        }
        
        if(table2 + ((int)floor(value/m) % m)== 0){
            //means nothing is there
            return 0;
        } else if (table2 + ((int)floor(value/m) % m)== 0){
            table2[((int)floor(value/m) % m)] = 0;
            cout << "REMOVED VALUE" << endl;
            return 1;
        }
    }
    return 0;
}

int HashTableCuckoo::load(string file){
    ifstream infile;
    infile.open(file);
    if(!infile){
        cout << "Loadfile Not Opened" << endl;
    }

    infile >> n >> m;
    int newTable[n];
    table = newTable;
    for(int x = 0; x < n; x++){
        table[x] = 0;
    }

    int * table1 = &table[0]; // hash function is x % m
    int * table2 = &table[m]; // has function is floor(value/m) % m

    int nextNum;
    for(int x = 0; x < n; x++){
        infile >> nextNum;
        insert(nextNum);
    }
    return 1;
}

void HashTableCuckoo::print(){
    for(int x = 0; x < m; x++){
        cout << "Table 1 Spot " << x << " = " << table[x];
        cout << "           ";
        cout << "Table 2 Spot " << x << " = " << table[x + m] << endl;
    }
}
