//
//  HeapPriorityQueue.hpp
//
//  Created by Wenjie Bai on 2/7/19.
//  Copyright © 2019 Wenjie Bai. All rights reserved.
//

#ifndef HeapPriorityQueue_hpp
#define HeapPriorityQueue_hpp

#include <stdio.h>
//#include <NotImplementedException.hpp>
//throw NotImplementedException whenever you are asked to pop something from an empty container.
#include <vector>
using namespace std;


template <typename Item>
class HeapPriorityQueue
{
public:
    HeapPriorityQueue( int capacity)
    {
        //complete constructor, might require initializer list
        currentSize = 0;
        array.resize(capacity);

    }
    
    
    bool empty( ) const
    {
        //complete function
        if ( currentSize == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    
    const Item& min( ) const
    {
        //complete function
        if (!empty()) {
           return array[0];
        }

    }
    
    
    void insert( const Item & x )
    {
        //complete function
        if (empty()) {
            array.push_back(x);
            currentSize++;
        }
        else {
            int i = currentSize;
            array.push_back(x);
            int child = i+1;
            int parent;
            int temp;
            while (child != 1) {
                parent = child/2;
                if ( array[parent-1] < array[child-1] ) {
                    break;
                }
                else {
                    temp = array[child-1];
                    array[child-1] = array[parent-1];
                    array[parent-1] = temp;
                    child = parent;
                }
            }
            currentSize++;
        }

    }    

    void removeMin( )
    {
       //complete function
       if (!empty()) {
            if (currentSize == 1) {
                array.clear();
                currentSize = 0;
            }
            else {
               vector<Item> temp;
               int tem;
               temp.resize(currentSize-1);
               temp[0] = array[currentSize-1];
               for ( int i = 1; i < currentSize-1; i++) {
                   temp[i] = array[i];
               }
               array = temp;
               currentSize--;
               int parent = 1;
               int child1;
               int child2;
               while(1) {
                   child1 = 2*parent;
                   child2 = 2*parent + 1;
                   if (child1 > currentSize) {
                       break;
                   }
                   if ( array[parent-1] < array[child1-1] && array[parent-1] < array[child2-1]) {
                       break;
                   }
                   if ( array[child1-1] < array[child2-1]) {
                        if ( array[parent-1] >= array[child1-1] ) {
                            tem = array[child1-1];
                            array[child1-1] = array[parent-1];
                            array[parent-1] = tem;
                            parent = child1;
                        }
                        else {
                            break;
                        }
                   }
                   else {
                       if (array[parent-1] >= array[child2-1]) {
                            tem = array[child2-1];
                            array[child2-1] = array[parent-1];
                            array[parent-1] = tem;
                            parent = child2;
                        }
                        else {
                            break;
                        }
                    }              
               }
           }
       }
    }


    int resize()
    {
        int size = currentSize;
        return size;
    }
    

private:
    int currentSize;  // Number of elements in heap
    vector<Item> array;        // The heap array
    
    

};
#endif /* HeapPriorityQueue_hpp */

