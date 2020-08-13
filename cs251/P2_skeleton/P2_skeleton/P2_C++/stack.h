 #include <iostream>
 #include <utility>
 #include<string>
 
 using namespace std;

 
 class Pair
 { 
	//TODO : Inplement Pair class
	public:
    int first;
	int second;
 };

 
 struct ListNode
 {
 	Pair data;
	ListNode * next;
	int c;
	int check;
	//Pair pair[8];
 };
 
 class Stack
 {
 	int stackSize;
	//int top;

	public:
	    //int check;
		Stack();
		void push(Pair item);
		Pair pop();
		ListNode *head;		
};
