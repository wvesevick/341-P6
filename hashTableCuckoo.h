#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

#include "hashtable.h"
#include "hashTableLinearProbing.h"

class HashTableCuckoo: public HashTable {
    private:
        int n;
        int m;
        int * table;
        int * table1;
        int * table2;
        ifstream loadfile;
        

    public:
        HashTableCuckoo();
        virtual ~HashTableCuckoo();

        virtual int insert(int value);
        virtual int search(int value);
        virtual int remove(int value);
        virtual int load(string file);

        virtual void print();

};

#endif
