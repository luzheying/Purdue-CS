#ifndef Rhymer_hpp
#define Rhymer_hpp

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

class Rhymer
{
    //add necessary constructors and methods following the provided documents
    public:
    
    void Qsort(string a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    string key = a[first];
 
    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }
 
        a[first] = a[last];
 
        while(first < last && a[first] <= key)
        {
            ++first;
        }
         
        a[last] = a[first];    
    }
    a[first] = key;
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

};

#endif // Rhymer_hpp
