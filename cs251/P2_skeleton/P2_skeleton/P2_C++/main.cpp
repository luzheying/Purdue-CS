#include <iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "stack.h"
#include "circular_deque.h"
using namespace std;


void read_part_1(ifstream &inputfile, ofstream &outputfile)
{
	// TODO: Part1 : Create stack
	Stack *st = new Stack();
	string str1 = "i";
	string str2 = "p";
	int line;
	inputfile >> line;
	string input;
	Pair temp;
	int tem1;
	int tem2;
	Pair p;
	int temp1;
	int temp2;
	ListNode *t;
	for ( int i = 0; i < line-1; i++) {
		inputfile >> input;
		if (input == str1) {
			inputfile >> tem1;
			inputfile >> tem2;
			temp.first = tem1;
			temp.second = tem2;
			st->push(temp);
		}
		else if (input == str2) {
			p = st->pop();
			temp1 = p.first;
			temp2 = p.second;
			if ( p.first == -1 && p.second == -1) {
				outputfile << "empty\n";
			}
			else {
				outputfile << p.first << " ";
				outputfile << p.second << "\n";
			}
		}
	}
		inputfile >> input;
			inputfile >> input;
		if (input == str1) {
			inputfile >> tem1;
			inputfile >> tem2;
			temp.first = tem1;
			temp.second = tem2;
			st->push(temp);
		}
		else if (input == str2) {
			p = st->pop();
			temp1 = p.first;
			temp2 = p.second;
			if ( p.first == -1 && p.second == -1) {
				outputfile << "empty";
			}
			else {
				outputfile << p.first << " " << p.second;
			}
		}
}

void read_part_2(ifstream &inputfile, ofstream &outputfile)
{
	//TODO: Part 2: Run the word search
	Stack *list = new Stack();
	int row;
	int col;
	inputfile >> row;
	inputfile >> col;
	int size = row * col;
	char str[row][col];
	for ( int i = 0; i < row; i++) {
		for ( int j = 0; j < col; j++) {
			char input;
			inputfile >> input;
			str[i][j]=input;
		}
	}
	char check[25];
	int len = 0;
	for (int i = 0; i < 25; i++){
		if (inputfile.eof()) {
			break;
		}
		len++;
		inputfile >> check[i];
	}
	
	int rcount = 0;
	int ccount = 0;
	Pair p;
	p.first = -1;
	p.second = -1;
	int count = 0;
	Pair current;
	int wcount = 0;
	for ( int r = 0; r < row; r++) {
		for ( int c = 0; c < col; c++) {
						if (str[r][c] == check[wcount]) {
							current.first = r;
							current.second  = c;
							list->push(current);
							count++;
							list->head->c = wcount;
				}
		}
	}
	if (count == 0) {
		goto end;
	}
	wcount++;
	count = 0;
	goto repeat;

	repeat:
		if (list->head == NULL) {
			goto end;
		}
		list->head->check++;
		if (list->head->check >1) {
			list->pop();
			if ( list->head == NULL) {
				goto end;
			}
			wcount = list->head->c+1;
			goto repeat;
		}

		if ( wcount+1 == len) {
			goto end;
		}
		if ( rcount == row-1 && ccount == row-1 ) {
			goto end;
		}
		rcount = list->head->data.first;
		ccount = list->head->data.second;
		for ( int r = rcount-1; r < rcount+2; r++) {
			for ( int c = ccount-1; c < ccount+2; c++) {
				if ( r > -1 && c > -1 && r < row && c < col) {
					if ( str[r][c] == check[wcount]) {
						current.first = r;
						current.second  = c;
						list->push(current);
						list->head->c = wcount;
						count++;
					}
				}
			}
		}

		if (count == 0) {
			list->pop();
			if ( list->head == NULL) {
				goto end;
			}
			wcount = list->head->c+1;
			goto repeat;
		}

		count=0;
		wcount++;
		goto repeat;


	end:
		if (wcount+1 == len) {
			Pair print[wcount];
			int c = wcount-1;
			while(list->head != NULL) {
				if (list->head->check == 1) {
					p = list->pop();
					print[c] = p;
					c--;
				}
				else {
					p = list->pop();
				}
			}
			for ( int i = 0; i < wcount-1; i++) {
				outputfile << print[i].first << " " << print[i].second << "\n";
			}
			outputfile << print[len-2].first << " " << print[len-2].second;
		}
		else {
			outputfile << "not found";
		}

}

void read_part_3(ifstream &inputfile, ofstream &outputfile)
{
	//TODO: Part 3: Circular double ended queue
	Deque *de = new Deque();
	int line;
	inputfile >> line;
	string func;
	string check;
	int num;
for ( int i = 0; i < line-1; i++) {
		inputfile >> func;
	if (func == "e") {
		inputfile >> check;
		inputfile >> num;
		if (check == "f") {
			de->enqueue_front(num);
		}else if(check == "b") {
			de->enqueue_back(num);
		}
	}
	else if ( func == "d") {
		inputfile >> check;
		if (check == "f") {
			num = de->dequeue_front();
			outputfile << num<< "\n";

		}else if(check == "b") {
			num = de->dequeue_back();
			outputfile << num << "\n";
		}
	}else if( func == "s") {
		int size = de->print_array_size();
		int front = de->print_front_index();
		int back = de->print_rear_index();
		outputfile << size << " " << front << " " << back << "\n";
	}
}
	inputfile >> func;
	if (func == "e") {
		inputfile >> check;
		inputfile >> num;
		if (check == "f") {
			de->enqueue_front(num);
		}else if(check == "b") {
			de->enqueue_back(num);
		}
	}
	else if ( func == "d") {
		inputfile >> check;
		if (check == "f") {
			num = de->dequeue_front();
			outputfile << num;

		}else if(check == "b") {
			num = de->dequeue_back();
			outputfile << num;
		}
	}else if( func == "s") {
		int size = de->print_array_size();
		int front = de->print_front_index();
		int back = de->print_rear_index();
		outputfile << size << " " << front << " " << back;
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
    
	class Pair;
	class Stack;
	struct ListNode;

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

