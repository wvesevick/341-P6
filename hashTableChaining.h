#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

#include "hashtable.h"

class HashTableChaining: public HashTable {
    private:
        int n;
        int k;
        list<int> * table;
        ifstream loadfile;
        

    public:
        HashTableChaining();
        virtual ~HashTableChaining();

        virtual int insert(int value);
        virtual int search(int value);
        virtual int remove(int value);
        virtual int load(string file);

        virtual void print();

};

#endif
