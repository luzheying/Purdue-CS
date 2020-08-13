#include <iostream>
#include "circular_deque.h"

using namespace std;

Deque::Deque( )
{
	//TODO: Write the Deque constructor
	//NOTE: Start with an array of size 2!
	front = -1;
	back = -1;
	count = 0;
	arrsize = 2;
	arr = new int[2];

}

void Deque::enqueue_front(int n)
{
	//TODO: Front enqueue method
	
	if (count == 0) {
		
		front = 0;
		back = 0;
		arr[0] = n;
		count++;
	}
	else if ( count == arrsize) {
		int size = arrsize;
		arrsize = arrsize * 2;
		int *temp;
		temp = new int[arrsize];
		int num =0;
		for ( int i = front ; i < size; i++) {
				temp[num] = arr[i];
				num++;
		}
		for ( int i = 0; i <= back; i++){
			temp[num] = arr[i];
			num++;
		}
		arr = temp;
		front = 0;
		back = size-1;
		front = arrsize-1;
		arr[front] = n;
		count++;
	}
	else{
		if ( front == 0) {
			front = arrsize-1;
		}
		else {
			front--;
		}
		arr[front] = n;
		count++;
	}
	
}

void Deque::enqueue_back(int n)
{
	//TODO: Back enqueue
	if (count == 0) {
		front = 0;
		back = 0;
		arr[back] = n;
		count++;
	}
	else if ( count == arrsize) {
		int size = arrsize;
		arrsize = arrsize * 2;
		int *temp;
		temp = new int[arrsize];
		int num = 0;
		for ( int i = front ; i < size; i++) {
				temp[num] = arr[i];
				num++;
		}
		for ( int i = 0; i <= back; i++){
			temp[num] = arr[i];
			num++;
		}
		arr = temp;
		front = 0;
		back = size-1;
		back++;
		arr[back] = n;
		count++;
	}
	else{
		if ( back == arrsize-1) {
			back = 0;
		}
		else {
			back++;
		}
		arr[back] = n;
		count++;
	}
}

int Deque::dequeue_front()
{	
	count--;
	int element;
	element = arr[front];
	arr[front] = -1;
	if (front == arrsize-1) {
		front = 0;
	}
	else {
	front++;
	}
	//TODO: front dequeue
	return element;
}

int Deque::dequeue_back()
{	
	count--;
	int element;
	element = arr[back];
	arr[back] = -1;
	if (back == 0) {
		back = arrsize-1;
	}
	else{
	back--;
	}
	//TODO: back dequeue
	return element;
}

int Deque::print_array_size()
{
	int size;
	//TODO: get the size of the allocated array
	size = arrsize;
	return size;
}

int Deque::print_front_index()
{
	int index;
	index = front;
	//TODO: get the front index
	return index;
}

int Deque::print_rear_index()
{
	int index;
	index = back;
	//TODO: get the rear index
	return index;
}