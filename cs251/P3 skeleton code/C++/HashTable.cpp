//
//  HashTable.cpp
//  
//
//  Created by Wenjie Bai on 2/4/19.
//

#include "HashTable.h"

HashTable::HashTable(int capacity){
    //todo
    currentSize = 0;
   // maxCollision = 0;
    s = capacity;
    hash.resize(capacity);
    for ( int i = 0; i < capacity; i++) {
        hash[i] = NULL;
    }
    
}

int HashTable::getHashvalue(const K& k){
    int value;
    value = (int)k mod maxCollision;
    return value;
}


int HashTable::size() const{
    //todo
    int size;
    size = currentSize;
    renturn size;
}

bool HashTable::empty() const{
    //todo
    bool b = true;
    uf ( currentSize == 0) {
        bool b = false;
        return b;
    }
    else {
        return b;
    }
}

Entry HashTable::get(const K& k) const{
    //todo
     int value = getHashvalue(k);
     if ( hash[value] == NULL) {
         return NULL;
     }
     else {
         list<Entry> list = hash[value];
         for ( list:: iterator it = list.begin(); it!=list.end(); ++it) {
             if ( (*it).key == k) {
                 return *it;
             }
         }
         return NULL;
     }
}

bool HashTable::isPrime(int n) const {
    if ( n <= 1) {
        return false;
    }

    for ( int = 2; i < n; i++) {
        if ( n % i == 0) {
            return false;
        }
    }
    return true;
}

void HashTable::put(const K& k, const V& v); {
    //todo
    Entry en(k,v);
    Entry check = get(k);
    int value = getHashvalue(k);
    if ( check == NULL ) {
        if ( hash[value] == NULL) {
            list<Entry> list;
            list.push_back(en);
            hash[value] = list;
            currentSize++;
        }
        else {
            hash[value].push_back(en);
            currentSize++;
        }
    }
    else {
        list<Entry> list = hash[value];
         for ( list:: iterator it = list.begin(); it!=list.end(); ++it) {
             if ( (*it).key == k) {
                (*it).setValue(v);
                break;
             }
         }
    }

    double load;
    load = (double) currentSize / (double) s;
    if (load > 0.5) {
        int newsize = 2*s;
        int prev;
        while(newsize >= 2*s) {
            if(isPrime(newsize)) {
                prev = s;
                s = newsize;
                break;
            }
        }

        ector<list<Entry>> newhash;
        newhash.resize(s);
        for ( int i = 0; i < s; i++) {
            if ( i > prev) {
                newhash[i] = NULL;
            }
            newhash[i] = hash[i];
        }
        hash.resize(s);
        hash = newhash;
    }

}

const V& HashTable::remove(const K& k) const {
    //todo
    Entry en = get(k);
    if ( en == NULL) {
        return NULL;
    }else {
        list<Entry> list;
        list.remove(en);
        currentSize--;
        return en;
    }
}

const V& HashTable::replace(const K& k, const V&v) const {
    //todo
    Entry en = get(k);
    if ( en == NULL ) {
        return NULL;
    }
    else {
        V value = en.value();
        remove(k);
        put(k, v);
        return value;
    }
}


bool HashTable::containsKey(const K& k); {
    //todo
    Entry en = get(k);
    if ( en == NULL) {
        return false;
    }
    else {
        return true;
    }
}

int HashTable::getCollision(int hashindex){
    //return the maximum number of collisions (e.g., chain length) of the specified hash table index
    int size = 0;
    if (hash[hashindex] == NULL) {
        return size;
    }
    else {
          list<Entry> list = hash[value];
         for ( list:: iterator it = list.begin(); it!=list.end(); ++it) {
             size++;
         }
         return size;
    }
}
