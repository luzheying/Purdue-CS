#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "Node.hpp"

using namespace std;

enum Color {RED, BLACK};

// typedef struct Nod
// { 
//     int data = 0; 
//     bool color = 0; 
//     Nod *left = NULL;
//     Nod *right = NULL;
//     Nod *parent = NULL; 
  
// }Nod;

struct Nod 
{ 
    int key; 
    bool color; 
    Nod *left, *right, *parent; 
  
    // Constructor 
    Nod(int key) 
    { 
       this->key = key; 
       left = right = parent = NULL; 
    } 
};

class BinarySearchTree
{
    public:
    int count = 0;
    Nod *root1;

    BinarySearchTree( ) {
        root1 = NULL;
    }

    // // A recursive function to do level order traversal 
    // void inorderHelper(node *root) 
    // { 
    //     if (root == NULL) 
    //         return; 
  
    //     inorderHelper(root->left); 
    //     cout << root->data << "  "; 
    //     inorderHelper(root->right); 
    // } 


    Nod* BSTInsert(Nod* root1, Nod *pt)
    { 
    /* If the tree is empty, return a new node */
     if (root1 == NULL) 
       return pt; 
    /* Otherwise, recur down the tree */
    if (pt->key < root1->key) 
    { 
        root1->left  = BSTInsert(root1->left, pt); 
        root1->left->parent = root1; 
    } 
    else if (pt->key > root1->key) 
    { 
        root1->right = BSTInsert(root1->right, pt); 
        root1->right->parent = root1; 
    } 
  
    /* return the (unchanged) node pointer */
        return root1; 
    }

// void levelOrderHelper(Nod *root) 
// { 
//     if (root == NULL) 
//         return; 
  
//     std::queue<Nod *> q; 
//     q.push(root); 
  
//     while (!q.empty()) 
//     { 
//         Nod *temp = q.front();
//         cout << temp->data << "  "; 
//         q.pop(); 
  
//         if (temp->left != NULL) 
//             q.push(temp->left); 
  
//         if (temp->right != NULL) 
//             q.push(temp->right); 
//     } 
// }

void rotateLeft(Nod *&root1, Nod *&pt)
{ 
    Nod *pt_right = pt->right; 
  
    pt->right = pt_right->left; 
  
    if (pt->right != NULL) 
        pt->right->parent = pt; 
  
    pt_right->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root1 = pt_right; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_right; 
  
    else
        pt->parent->right = pt_right; 
  
    pt_right->left = pt; 
    pt->parent = pt_right; 
}

void rotateRight(Nod *&root1, Nod *&pt) 
{ 
    Nod *pt_left = pt->left; 
  
    pt->left = pt_left->right; 
  
    if (pt->left != NULL) 
        pt->left->parent = pt; 
  
    pt_left->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root1 = pt_left; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_left; 
  
    else
        pt->parent->right = pt_left; 
  
    pt_left->right = pt; 
    pt->parent = pt_left; 
} 

// This function fixes violations caused by BST insertion 
void fixViolation(Nod *&root1, Nod *&pt) 
{ 
    Nod *parent_pt = NULL; 
    Nod *grand_parent_pt = NULL; 
  
    while ((pt != root1) && (pt->color != BLACK) && 
           (pt->parent->color == RED)) 
    { 
  
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
  
        /*  Case : A 
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            Nod *uncle_pt = grand_parent_pt->right; 
  
            /* Case : 1 
               The uncle of pt is also red 
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == RED) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } else
            { 
                /* Case : 2 
                   pt is right child of its parent 
                   Left-rotation required */
                if (pt == parent_pt->right) 
                { 
                    rotateLeft(root1, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is left child of its parent 
                   Right-rotation required */
                rotateRight(root1, grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 

        /* Case : B 
           Parent of pt is right child of Grand-parent of pt */
        else
        { 
            Nod *uncle_pt = grand_parent_pt->left; 
  
            /*  Case : 1 
                The uncle of pt is also red 
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   pt is left child of its parent 
                   Right-rotation required */
                if (pt == parent_pt->left) 
                { 
                    rotateRight(root1, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is right child of its parent 
                   Left-rotation required */
                rotateLeft(root1, grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
    } 
  
    root1->color = BLACK; 
} 

// Nod *createNode(int key) {
//         Nod *tem = new Nod;
//         tem->key = key;
//         tem->left = NULL;
//         tem->right = NULL;
//         tem->parent = NULL;
//         tem->color = 0;
//     }

// Function to insert a new node with given data 
void insert(const int &key)
{
    //cout << "check!!!!!!!!!!\n"; 
    Nod *pt = new Nod(key); 
  
    // Do a normal BST insert 
    root1 = BSTInsert(root1, pt);
  
    // fix Red Black Tree violations 
    fixViolation(root1, pt); 
}

Nod *finddata( Nod *&ro, int key) {
    if (ro == NULL) {
        return NULL;
    }
    if (ro->key == key) {
        return ro;
    }
    if (ro->key < key) {
         return finddata(ro->right, key);
     }
     else {
          return finddata(ro->left, key); 
     }
}

int Bheight(Nod *tem, int key) {
    if ( tem== NULL) {
        return 0;
    }
    //cout << tem->key << "=======\n";
   else{
        if ( tem->color == BLACK) {
            return Bheight(tem->right, key) + 1;
        }

         return Bheight(tem->right, key);
            
        }
        // tem = tem->left;
        // if ( tem->color == BLACK) {
        //     count++;
        // }
       // cout << tem->key << "=======\n";
         
    }

    private:
    
    



    //add necessary constructors and methods following the provided documents

};

#endif // BinarySearchTree_hpp
