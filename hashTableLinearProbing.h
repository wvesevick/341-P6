#ifndef HASHTABLELINEARPROBING_H
#define HASHTABLELINEARPROBING_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "hashtable.h"

class HashTableLinearProbing: public HashTable {
    private:
        int n;
        int k;
        int m;
        int * table;
        ifstream loadfile;
        

    public:
        HashTableLinearProbing();
        virtual ~HashTableLinearProbing();

        int rehash();

        virtual int insert(int value);
        virtual int search(int value);
        virtual int remove(int value);
        virtual int load(string file);

        virtual void print();

};

#endif
