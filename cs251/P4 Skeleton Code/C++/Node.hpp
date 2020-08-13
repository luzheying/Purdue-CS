#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <vector>

using namespace std;

typedef struct node{
        int key = 0;
        node *left = NULL;
        node *right = NULL;
        // node *parent = NULL;
        // bool color = 0;
    }node;


class Node
{
    //add necessary variables and functions
    public:
    node *root = NULL;

    Node(node *node) {
        root = node;
    }

    node *createNode(int key) {
        node *tem = new node;
        tem->key = key;
        tem->left = NULL;
        tem->right = NULL;
        // tem->parent = NULL;
        // tem->color = 0;
    }

    void insertKey(node* node, int key) {
        if (node == NULL) {
            node = createNode(key);
            
            if ( count > 0 && key > temp->key ) {
                temp->right = node;
            }
            else if (count > 0 && key < temp->key){
                temp->left = node;
            }
            if ( count == 0) {
                root = node;
            }
            count++;
            return;
        }
        else if (key < node->key) {
            temp = node;
            insertKey(node->left, key);
         }
         else if (key > node->key) {
             temp = node;
            insertKey(node->right, key);    
         }
    }

    node* deleteKey(node* root, int key) 
    { 
    if (!searchKey(root, key)) {
        return NULL;
    }
    if (root == NULL) return root; 
    if (key < root->key) 
        root->left = deleteKey(root->left, key); 
    else if (key > root->key) 
        root->right = deleteKey(root->right, key); 
    else
    {  
        if (root->left == NULL) 
        { 
            temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            temp = root->left; 
            free(root); 
            return temp; 
        } 
        temp = minValueNode(root->right); 
        root->key = temp->key; 
        root->right = deleteKey(root->right, temp->key); 
    } 
    return root; 
} 

node * minValueNode(struct node* node) 
{ 
    current = node; 
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

    bool searchKey( node* node, int key) {
        if (node == NULL) {
            return false;
        }
        if (node->key == key) {
            return true;
        }
     if (node->key < key) {
         return searchKey(node->right, key);
     }
     else {
          return searchKey(node->left, key); 
     }
    }


    node *findKey( node* node, int key) {
        if (node == NULL) {
            return NULL;
        }
        if (node->key == key) {
            return node;
        }
     if (node->key < key) {
         return findKey(node->right, key);
     }
     else {
          return findKey(node->left, key); 
     }
    }

    int rangeSum(node* node, int left, int right) {
        ans = 0;
        dfs(root, left, right);
        return ans;
    }

    void dfs(node* node, int left, int right) {
        if (node != NULL) {
            if (left <= node->key && node->key <= right)
                ans += node->key;
            if (left < node->key)
                dfs(node->left, left, right);
            if (node->key < right)
                dfs(node->right, left, right);
        }
    }

    int height(node *node, int key) {
        int count = 0;
        if (searchKey(root,key)) {
            while(true) {
                if (key == node->key) {
                    return count;
                }
                if (key > node->key) {
                    count++;
                    node = node->right;
                }
                else if (key < node->key) {
                    count++;
                    node = node->left;
                }
            }

        }
        return -1;
    }

    int LCA( node *root, int key1, int key2) {
        int output = -1;
       // cout << "===========================\n";
        if (searchKey(root, key1) && searchKey(root, key2)) {
          //  cout << "1111111111===========================\n";
            vector<int> k1;
            vector<int> k2;
            temp = root;
            while(true) {
              //  cout << "1111111111=====22222222222======================\n";
                if ( temp == NULL) {
                    break;
                }
                if (key1 == temp->key) {
                    k1.push_back(temp->key);
                 //    cout << "k1 complete ==================\n";
                    break;
                }
                if ( key1 < temp->key) {
                    k1.push_back(temp->key);
                    temp = temp->left;
                }
                else {
                    k1.push_back(temp->key);
                    temp = temp->right;
                }
            }
            temp = root;
            while(true) {
             //   cout << "1111111111=====22222222222=======333333===============\n";
                if ( temp == NULL) {
                    break;
                }
                if (key2 == temp->key) {
                    k2.push_back(temp->key);
                   // cout << "k2 complete ==================\n";
                    break;
                }
                if ( key2 < temp->key) {
                    k2.push_back(temp->key);
                    temp = temp->left;
                }
                else {
                    k2.push_back(temp->key);
                    temp = temp->right;
                }
            }
            for (vector<int>::iterator it1 = k1.end()-1; it1 >= k1.begin(); it1--) {
                for (vector<int>::iterator it2 = k2.end()-1; it2 >= k2.begin(); it2--) {
                    // cout << *it1 << " k1 !!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    // cout << *it2 << " k2 !!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    if ( *it1 == *it2) {
                    //    cout << "k1=k2!!!!!!!!!!!!\n";
                        output = *it1;
                   //     cout << output << "check!!!!!!!!!!!!!!!!\n";
                         return output;
                    }
                }
               //  cout << output << "check==========!!!!!!!!!!!!!!!!\n";
            }
       //      cout << output << "check111111==========!!!!!!!!!!!!!!!!\n";
            //return output;
        }
        return output;
    }

    int floor( node *root, int key) {
      //  cout << "check1\n";
        for ( int i = key; i >= 0; i--) {
            if (searchKey(root, i)) {
                return i;
            }
        }
        return 0;
    }

    int ceil( node *root, int key) {
       // cout << "check2\n";
       int max = 0;
       temp = root;
       while(temp->right != NULL) {
           temp = temp->right;
       }
       max = temp->key;
        for ( int i = key; i <= max; i++) {
            if (searchKey(root, i)) {
                return i;
            }
        }
        return 0;
    }

    int dist(node *node, int key1, int key2) {
        if ( key1 < 0 || key2 < 0 || !searchKey(node,key1) || !searchKey(node,key2)) {
      //      cout << "check1\n";
            return -1;
        }
        if (key1 == key2) {
        //    cout << "check2\n";
            return 0;
        } 
        if (key1 == node->key) {
      //      cout << "check3\n";
            return height(node, key2);
        }
        else if (key2 == node->key) {
       //     cout << "check4\n";
            return height(node, key1);
        }
        else if ( key1 < node->key && key2 > node->key) {
      //      cout << "check5\n";
            return height(node, key1) + height(node, key2);
        }
        else if ( key2 < node->key && key1 > node->key) {
     //       cout << "check6\n";
            return height(node, key1) + height(node, key2);
        }
        else if (LCA(node, key1, key2) > key1 && LCA(node, key1, key2) < key2) {
       //     cout << "check7\n";
            return height(node, key2) + height(node, key1) - 2*height(node, LCA(node, key1,key2));
        }
        else if (LCA(node, key1, key2) < key1 && LCA(node, key1, key2) > key2) {
       //     cout << "check8\n";
            return height(node, key2) + height(node, key1) - 2*height(node, LCA(node, key1,key2));
        }
        else if(key1 > key2) {
       //     cout << "check9\n";
            return height(node, key1) - height(node, key2);
        }
        else{
       //     cout << "check10\n";
            return height(node, key2) - height(node, key1);
        }
        return 0;
    }



    private:
    // node *parent = NULL;
    node *current = NULL;
    node *temp = NULL;
    node* temleft = NULL;
    node* temright = NULL;
    int ans = 0;
    int count = 0;
    int ceilnum = 0;

};

#endif // Node_hpp

