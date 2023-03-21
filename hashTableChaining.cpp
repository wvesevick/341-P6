#include "hashTableChaining.h"
#include "hashtable.h"

//LINEAR PROBING NOTES
//EVERYTHING WORKS EXCEPT
//FIRST INSERT DOES NOT GO


HashTableChaining::HashTableChaining(){ // hash function is x % n
    cout << "How large would you like the table" << endl;
    cin >> n;
    table = new list<int>[n];
}

HashTableChaining::~HashTableChaining(){

}

int HashTableChaining::insert(int value){
    int insertVal = value % n;
    table[insertVal].push_back(value);

    return 1;
}

int HashTableChaining::search(int value){
    int searchVal = value % n;
    list<int>::iterator it;
    for(it = table[searchVal].begin(); it != table[searchVal].end(); it++){
        if(*it == value){
            cout << "VALUE FOUND" << endl;
            return 1;
        }
    }
    return 0;
}

int HashTableChaining::remove(int value){
    int removeVal = value % n;
    list<int>::iterator it;
    for(it = table[removeVal].begin(); it != table[removeVal].end(); it++){
        if(*it == value){
            cout << "VALUE FOUND" << endl;
            break;
        }
    }

    if( it != table[removeVal].end()){
        table[removeVal].erase(it);
        cout << "SUCCESSFULLY DELETE " << value << endl;
        return 1;
    }

    return 0;
}

int HashTableChaining::load(string file){
    int k;
    ifstream infile;
    infile.open(file);
    if(!infile){
        cout << "Loadfile Not Opened" << endl;
    }

    infile >> n >> k;
    table = new list<int>[n];

    int nextNum;
    for(int x = 0; x < k; x++){
        infile >> nextNum;
        insert(nextNum);
    }
    return 0;
}

void HashTableChaining::print(){
    for (int i = 0; i < n; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}
