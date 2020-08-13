//
//  HashTable.hpp
//  SeperateChaining
//
//  Created by Wenjie Bai on 2/6/19.
//  Copyright © 2019 Wenjie Bai. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include<iostream>
//#include <NotImplementedException.hpp>
//throw NotImplementedException whenever you are asked to pop something from an empty container.
#include <list>
#include <vector>
#include <string>
using namespace std;


const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};

template <typename V> class
Entry {
public:
    Entry(const string& k, const V& v)
    :   _key(k),   _value(v) { }
    const string& getkey() const {return _key;}
    const V& getvalue() const {return _value;}
private:
    string _key;
    V _value;
};

template <typename V>
class HashTable
{
public:

    HashTable( int capacity )
    {
        currentSize = 0;
        cap = capacity;
        theLists.resize(capacity);
        totalSize = 0;
    }
    

    int size()
    {
        //complete function
        int size = totalSize;
        return size;
    }
    
    int hashCode(const string& s )
    {
        //complete function
        int size = 0;
        int key = 0;
        int add;
        size = s.size();
        for( int i =0; i < size; i++) {
            if (isdigit(s[i])) {
                add = s.at(i) - '0';
                key = key + add;
            }
            else {
                key = key + (int)s.at(i);
            }
        }
        return key;
    }
    
    int hashValue(const int hashcode)
    {
        //complete function
        int hashValue = hashcode % cap;
        return hashValue;
    }


    V get(const string& k)
    {
        //complete function
         int hashC = hashCode(k);
        int value = hashValue(hashC);
        if ( theLists[value].empty()) {
            return 0;
        }
        else {
            list<Entry<V>> list = theLists[value];
            typename list<Entry<V>>::iterator it;
            for ( it = list.begin(); it!=list.end(); ++it) {
                if (it->getkey() == k) {
                    return it->getvalue();
                }
             }
            return 0;
        }
    }
    

    void rehash() {
        if ((double) currentSize / (double)cap > 0.5) {
            int prev = cap;
            int i = 0;
            while( primes[i] < 2*cap) {
                i++;
            }
            cap = primes[i];
            vector<list<Entry<V>>> newhash;
            newhash = theLists;
            theLists.clear();
            theLists.resize(cap);
            for ( int i = 0; i < prev; i++) {
                if ( !newhash[i].empty()) {
                    list<Entry<V>> hashlist = newhash[i];
                    string keyH = hashlist.front().getkey();
                    int hashC = hashCode(keyH);
                    int value = hashValue(hashC);
                    theLists[value] = hashlist;
                }
            }
        }
        
    }

    V remove( const string& k )
    {
        //complete function
       int hashC = hashCode(k);
        int value = hashValue(hashC);
        if ( theLists[value].empty()) {
            return 0;
        }
        else {
            V v = 0;
            list<Entry<V>> list = theLists[value];
           typename list<Entry<V>>::iterator it;
                    for ( it = list.begin(); it!=list.end(); ++it) {
                        if (it->getkey() == k) {
                            v = it->getvalue();
                            list.erase(it);
                            break;
                        }
                    }
            theLists[value] = list;
            if ( theLists[value].empty()) {
                currentSize--;
            }
            totalSize--;
            return v;
        }
    }

    V put(const string& k, const V& v)
    {
        //complete function
        Entry<V> en(k,v);
        int hashC = hashCode(k);
        int value = hashValue(hashC);
        totalSize++;
        if ( !contains(k)) {
            if ( theLists[value].empty()) {
                list<Entry<V>> list;
                list.push_back(en);
                theLists[value] = list;
                currentSize++;
                return 0;
            }
            else {
                list<Entry<V>> list = theLists[value];
                list.push_back(en);
                theLists[value] = list;
                return 0;
            //     list<Entry<V>> list = theLists[value];
            //     string ck = list.front().getkey();
            //     int size1 = ck.length();
            //     int size2 = k.length();
            //     if (size1 == size2) {
            //         int ckchar[size1];
            //         int kchar[size2];
            //         for (int i = 0; i < size1; i++) {
            //             ckchar[i] = (int)ck.at(i);
            //             kchar[i] = (int)k.at(i);
            //         }
            //         for (int m = 0; m < size1; m++) {
            //             for ( int n = 0; n < size1; n++) {
            //                 if (ckchar[m] == kchar[n]) {
            //                     ckchar[m] = -1;
            //                     kchar[n] = -1;
            //                     size2--;
            //                     break;
            //                 }
            //             }
            //         }
            //         if (size2 == 0) {
            //             V v = remove(k);
            //             list.push_back(en);
            //             theLists[value] = list;
            //             return v;
            //         }
            //         else {
            //             theLists[value].push_back(en);
            //         return 0;
            //         }
            //     }
                
            //     else{
            //         theLists[value].push_back(en);
            //         return 0;
            //     }
            // }
          }
        }
        else {
            V v = remove(k);
            if (theLists[value].empty()) {
                currentSize++;
                list<Entry<V>> list;
                list.push_back(en);
                theLists[value] = list;
                return v;
            }
            list<Entry<V>> list = theLists[value];
            list.push_back(en);
            theLists[value] = list;
            return v;
        }
    }


    bool contains(const string& k)
    {
        //complete function
       int hashC = hashCode(k);
        int value = hashValue(hashC);
        if ( theLists[value].empty()) {
            return false;
        }
        else {
            list<Entry<V>> list = theLists[value];
            typename list<Entry<V>>::iterator it;
                    for ( it = list.begin(); it!=list.end(); ++it) {
                        if (it->getkey() == k) {
                            return true;
                        }
                    }
             return false;
        }
    }
    
    size_t getCollision(int hashIndex)
    {
        //complete function
    
        if (theLists[hashIndex].empty()) {
            return 0; 
        }
        else {
            list<Entry<V>> list = theLists[hashIndex];
            return list.size();
        }
    }

    V replace(const string& k, const V& v) {
        if ( contains(k) ) {
            V value = get(k);
            put(k,v);
            return value;
        }
        return 0;
    }    
    
private:
    vector<list<Entry<V>>> theLists;   // The array of Lists
    int currentSize;
    int totalSize;
    int cap;
    

};
#endif /* HashTable_hpp */
