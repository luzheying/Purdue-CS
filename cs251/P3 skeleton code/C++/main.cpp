// #include <iostream>
// #include<string>
// #include<sstream>
// #include<fstream>
// #include<vector>
// #include "HashTable.h"
// #include "HeapPriorityQueue.h"
// using namespace std;


#include<sstream>
#include<fstream>

#include "HashTable.hpp"
#include "HeapPriorityQueue.hpp"
//#include <NotImplementedException.hpp>

using namespace std;

void read_part_1(ifstream &inputfile, ofstream &outputfile)
{
	// TODO: Part1 : Create hash table
	int cap;
	int initial = 2;
	string func;
	string keyvalue;
	int value;
	int index;
	int v;
	int size;
	int s;
	bool test;
	inputfile >> cap;
	HashTable< int > h = HashTable< int >(initial);
	for ( int i = 0; i < cap-1; i++) {
		inputfile >> func;
		if (func=="p") {
			inputfile >> keyvalue >> value;
			v = h.put(keyvalue, value);
			h.rehash();
			if (v == 0) {
				outputfile << "null\n";
			}
			else {
				outputfile << v << "\n";
			}
		}
		else if ( func == "g") {
			inputfile >> keyvalue;
			v = h.get(keyvalue);
			if ( v == 0) {
				outputfile << "null\n";
			}
			else {
				outputfile << v << "\n";
			}
		}
		else if ( func == "r") {
			inputfile >> keyvalue >> value;
			v = h.replace(keyvalue, value);
			if ( v == 0) {
				outputfile << "null\n";
			}
			else{
				outputfile << v << "\n";
			}
		}
		else if ( func == "s") {
			size = h.size();
			outputfile << size << "\n";
			
		}
		else if ( func == "m") {
			inputfile >> index;
			s = h.getCollision(index);
			outputfile << s << "\n";

		}
		else if (func == "c") {
			inputfile >> keyvalue;
			test = h.contains(keyvalue);
			if (test) {
				v = 1;
			}
			else {
				v = 0;
			}
			outputfile << v << "\n";
		}
		else if ( func == "d") {
			inputfile >> keyvalue;
			v = h.remove(keyvalue);
			if ( v == 0) {
				outputfile << "null\n";
			}
			else {
				outputfile << v << "\n";
			}
		}
	}
		inputfile >> func;
		if (func=="p") {
			inputfile >> keyvalue >> value;
			v = h.put(keyvalue,value);
			h.rehash();
			if (v == 0) {
				outputfile << "null";
			}
			else {
				outputfile << v;
			}
		}
		else if ( func == "g") {
			inputfile >> keyvalue;
			v = h.get(keyvalue);
			if ( v == 0) {
				outputfile << "null";
			}
			else {
				outputfile << v;
			}
		}
		else if ( func == "r") {
			inputfile >> keyvalue >> value;
			v = h.replace(keyvalue, value);
			if ( v == 0) {
				outputfile << "null";
			}
			else{
				outputfile << v;
			}
		}
		else if ( func == "s") {
			size = h.size();
			outputfile << size;
			
		}
		else if ( func == "m") {
			inputfile >> index;
			s = h.getCollision(index);
			outputfile << s;
		}
			else if ( func == "d") {
			inputfile >> keyvalue;
			v = h.remove(keyvalue);
			if ( v == 0) {
				outputfile << "null";
			}
			else {
				outputfile << v;
			}
		}

}

void read_part_2(ifstream &inputfile, ofstream &outputfile)
{
	//TODO: Part 2: compute number of collisions
	int cap;
	int initial = 2;
	string func;
	string keyvalue;
	int value;
	int index;
	int v;
	int size;
	int s;
	bool test;
	inputfile >> cap;
	HashTable< int > h = HashTable< int >(initial);
	for ( int i = 0; i < cap-1; i++) {
		inputfile >> func;
		if (func=="p") {
			inputfile >> keyvalue >> value;
			v = h.put(keyvalue, value);
			h.rehash();
			if (v == 0) {
				outputfile << "null\n";
			}
			else {
				outputfile << v << "\n";
			}
		}
		else if ( func == "g") {
			inputfile >> keyvalue;
			v = h.get(keyvalue);
			if ( v == 0) {
				outputfile << "null\n";
			}
			else {
				outputfile << v << "\n";
			}
		}
		else if ( func == "r") {
			inputfile >> keyvalue >> value;
			v = h.replace(keyvalue, value);
			if ( v == 0) {
				outputfile << "null\n";
			}
			else{
				outputfile << v << "\n";
			}
		}
		else if ( func == "s") {
			size = h.size();
			outputfile << size << "\n";
			
		}
		else if ( func == "m") {
			inputfile >> index;
			s = h.getCollision(index);
			outputfile << s << "\n";

		}
		else if (func == "c") {
			inputfile >> keyvalue;
			test = h.contains(keyvalue);
			if (test) {
				v = 1;
			}
			else {
				v = 0;
			}
			outputfile << v << "\n";
		}
		else if ( func == "d") {
			inputfile >> keyvalue;
			v = h.remove(keyvalue);
			if ( v == 0) {
				outputfile << "null\n";
			}
			else {
				outputfile << v << "\n";
			}
		}
	}
		inputfile >> func;
		if (func=="p") {
			inputfile >> keyvalue >> value;
			v = h.put(keyvalue,value);
			h.rehash();
			if (v == 0) {
				outputfile << "null";
			}
			else {
				outputfile << v;
			}
		}
		else if ( func == "g") {
			inputfile >> keyvalue;
			v = h.get(keyvalue);
			if ( v == 0) {
				outputfile << "null";
			}
			else {
				outputfile << v;
			}
		}
		else if ( func == "r") {
			inputfile >> keyvalue >> value;
			v = h.replace(keyvalue, value);
			if ( v == 0) {
				outputfile << "null";
			}
			else{
				outputfile << v;
			}
		}
		else if ( func == "s") {
			size = h.size();
			outputfile << size;
			
		}
		else if ( func == "m") {
			inputfile >> index;
			s = h.getCollision(index);
			outputfile << s;
		}
			else if ( func == "d") {
			inputfile >> keyvalue;
			v = h.remove(keyvalue);
			if ( v == 0) {
				outputfile << "null";
			}
			else {
				outputfile << v;
			}
		}
}

void read_part_3(ifstream &inputfile, ofstream &outputfile)
{
	//TODO: Part 3: create heap
	int line;
	inputfile >> line;
	string func;
	int key;
	bool em;
	int out;
	int size = 0;
	HeapPriorityQueue<int> h = HeapPriorityQueue<int>(size);
	
	for ( int i = 0; i < line-1; i++) {
		inputfile >> func;
		if ( func == "i" ) {
			inputfile >> key;
			h.insert(key);
		}
		else if (func == "m") {
			em = h.empty();
			if ( em == true) {
				outputfile << "empty\n";
			}
			else {
				out = h.min();
				outputfile << out << "\n";
			}
		}
		else if ( func == "r") {
			em = h.empty();
			if ( em == true) {
				outputfile << "empty\n";
			}
			else {
				h.removeMin();
			}
		}
		else if (func == "s") {
			
			em = h.empty();
			if ( em == true) {
				outputfile << "empty\n";
			}
			else {
				size = h.resize();
				for ( int i = 0; i < size; i++) {
					out = h.min();
					outputfile << out << "\n";
					h.removeMin();
				}
			}
		}
	}
	inputfile >> func;
		if ( func == "i" ) {
			inputfile >> key;
			h.insert(key);
		}
		else if (func == "m") {
			em = h.empty();
			if ( em == true) {
				outputfile << "empty";
			}
			else {
				out = h.min();
				outputfile << out;
			}
		}
		else if ( func == "r") {
			em = h.empty();
			if ( em == true) {
				outputfile << "empty";
			}
			else {
				h.removeMin();
			}
		}
		else if (func == "s") {
			em = h.empty();
			if ( em == true) {
				outputfile << "empty";
			}
			else {
				size = h.resize();
				for ( int i = 0; i < size-1; i++) {
					out = h.min();
					outputfile << out << "\n";
					h.removeMin();
				}
				out = h.min();
				outputfile << out;
				h.removeMin();
			}
		}

}


int main(int argc, char *argv[])
{
	// Read in the test case
	ifstream inputfile;
	ofstream outputfile;
	
	inputfile.open(argv[1]);
	outputfile.open(argv[2]);

	string str;
	
	getline(inputfile, str);
	int part;
	stringstream convert(str);
	convert >> part; 

	switch(part)
	{
		case 1:
			read_part_1(inputfile, outputfile);
			break;
		case 2:
			read_part_2(inputfile, outputfile);
			break;
		case 3:
			read_part_3(inputfile, outputfile);
			break;
	}
	
	return 0;
}

