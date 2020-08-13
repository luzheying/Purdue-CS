 #include "stack.h"
 #include <utility>
 
 using namespace std;


 Stack::Stack()
 {
	 //TODO: Write the constructor
	stackSize = 0;
	head = NULL;

 }
 
 void Stack::push(Pair p)
 {   
	 //TODO: Write the push method
	stackSize = stackSize + 1;
	ListNode *node = new ListNode;
	node->check = 0;
	node->c =0;
	(node->data).first = p.first;
	(node->data).second = p.second;
    node->next = head;
	head = node;
 }
 
 Pair Stack::pop()
 {
	Pair p;
	if ( head == NULL ) {
		p.first = -1;
		p.second = -1;
		return p;
	}
	//TODO: Write the pop method
	p.first = head->data.first;
	p.second = head->data.second;
	if (head->next == NULL) {
		free(head);
		head = NULL;
		stackSize--;
		return p;
	}
    head = head->next;
	stackSize--;
 	return p;
 }

