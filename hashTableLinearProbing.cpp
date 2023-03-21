#include "hashTableLinearProbing.h"
#include "hashtable.h"

//LINEAR PROBING NOTES
//EVERYTHING WORKS EXCEPT
//FIRST INSERT DOES NOT GO


HashTableLinearProbing::HashTableLinearProbing(){ // hash function is x % n
    cout << "How large would you like the table" << endl;
    cin >> n;
    int m = n/2;
    int newTable[n];
    table = newTable;
    ifstream loadFile ("loadfile.txt");
    for(int x = 0; x < n; x++){
        table[x] = 0;
    }

}

HashTableLinearProbing::~HashTableLinearProbing(){

}
int HashTableLinearProbing::rehash(){
    if(m+3 > 21){
        cout << "CANNOT HASH M TOO LARGE" << endl;
        return 0;
    }
    m += 3;
    n = 2 * m;
    int newHashTable[n];
    int * tempTable;
    tempTable = table;
    table = newHashTable;
    for(int x = 0; x < n; x++){
        table[x] = 0;
    }
    for(int x = 0; x < n - 6; x++){
        int value = tempTable[x];
        this->insert(value);
    }
}

int HashTableLinearProbing::insert(int value){
    int insertVal = value % n;
    int totalTries = 0;
    while (totalTries < n){
        if(table[insertVal] == value){
            cout << "Number Already In Table" << endl;
            return 1;
        }
        if(table[insertVal] == 0){
            table[insertVal] = value;
            cout << "SUCCESSFUL INSERT OF " << value << " INTO " << insertVal << endl;
            return 1;
        } else {
            insertVal++;
            totalTries ++;
            if(insertVal == n){
                insertVal = 0;
            }
        }
    }
    cout << "REHASH CALLED " << endl;
    //rehash();
    return 0;
}

int HashTableLinearProbing::search(int value){
    int searchVal = value % n;
    int totalTries = 0;
    while(totalTries < n){
        if(table[searchVal] == value){
            cout << "FOUND " << value << " IN SPOT " << searchVal << endl;
            return 1;
        } else {
            searchVal++;
            totalTries++;
            if(searchVal == n){
                searchVal = 0;
            }
        }
    }
    cout << "NUMBER NOT FOUND" << endl;
    return 0;
}

int HashTableLinearProbing::remove(int value){
    int removeVal = value % n;
    int totalTries = 0;
    while(totalTries < n){
        if(table[removeVal] == value){
            cout << "REMOVING " << value << " IN SPOT " << removeVal << endl;
            table[removeVal] = 0;
            return 1;
        } else {
            removeVal++;
            totalTries++;
            if(removeVal == n){
                removeVal = 0;
            }
        }
    }
    cout << "NUMBER NOT FOUND" << endl;
    return 0;
}

int HashTableLinearProbing::load(string file){
    int k;
    ifstream infile;
    infile.open(file);
    if(!infile){
        cout << "Loadfile Not Opened" << endl;
    }

    infile >> n >> k;
    int newTable[n];
    table = newTable;
    for(int x = 0; x < n; x++){
        table[x] = 0;
    }


    int nextNum;
    for(int x = 0; x < k; x++){
        infile >> nextNum;
        insert(nextNum);
    }

}

void HashTableLinearProbing::print(){
    for(int x = 0; x < n; x++){
        cout << "Table Spot " << x << " = " << table[x] << endl;
    }
}
