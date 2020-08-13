#include <iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>

#include "Node.hpp"
#include "Rhymer.hpp"
#include "BinarySearchTree.hpp"

using namespace std;

ifstream inputfile;
ofstream outputfile;
int check = 0;

void read_part_1(ifstream &inputfile, ofstream &outputfile)
{

    //TODO: sorting
    int par;
    inputfile >> par;
    Rhymer r;
    if (par==1) {
        int line1;
        inputfile >> line1;
        string arr[line1];
        for ( int i = 0; i < line1; i++) {
            inputfile >> arr[i];
            reverse(arr[i].rbegin(), arr[i].rend());
        }
        r.Qsort(arr, 0, line1-1);
        for ( int j = 0; j < line1; j++) {
            reverse(arr[j].rbegin(), arr[j].rend());
            outputfile << arr[j] << "\n";
        }
    }


    else {
       // cout << "get into part 2!!!!!!!!\n";
       Rhymer r;
        int k;
        inputfile >> k;
        int line2;
        inputfile >> line2;
        string arr[line2];
        int row = 1;
        int lenmax = 0;
        for ( int i = 0; i < line2; i++) {
            inputfile >> arr[i];
            reverse(arr[i].rbegin(), arr[i].rend());
      //      cout << arr[i] << "+++++++++++\n";
            if (arr[i].length() > lenmax) {
                lenmax = arr[i].length();
            }
        }
        r.Qsort(arr, 0, line2-1);
        int size = line2*10;
        //vector<string> keyval;
        string keyval[size];
      //  cout << "check1\n";
        string ap;
        int exist = 0;
       // int ex = 0;
       // int key = 0;
       int index = 0;
        for ( int b = 0; b < line2; b++) {
            for ( int c = 0; c < lenmax; c++) {
                if ( c <= arr[b].length()) {
                    //cout << "check1\n";
                    ap = arr[b].substr(0, c+1);

                if ( index == 0) {
                    keyval[index] = ap;
                    index++; 
                }
                else {
         //           cout << "check2\n";
                    for( int i = 0; i < index; i++) {
             //            cout << index << "check3\n";
                      if ( keyval[i] == ap) {
                        //  cout << "check4\n";
                            exist = 1;
                            break;
                        }
                }
                if ( exist == 1) {
                        exist = 0;
                        //break;
                }
                  else {
                      keyval[index] = ap;
                      index++;
                      //break;
                  }
                }
                    //      if ( ap == "debba") {
                  
                    // }
                // if ( keyval[0] == ) {
                //         keyval.push_back(ap);
                // }
                // else {
                // for (vector<string>::iterator it = keyval.begin(); it != keyval.end(); ++it) {
                
                
                 
            }
          }
        }

        //r.Qsort(keyval, 0, index-1);
       // cout << index << "!!!!!\n";

        for ( int j = 0; j < index; j++) {
            reverse(keyval[j].rbegin(), keyval[j].rend());
      //      cout << arr[i] << "+++++++++++\n";
        }
        r.Qsort(keyval, 0, index-1);
        for ( int j = 0; j < index; j++) {
            reverse(keyval[j].rbegin(), keyval[j].rend());
      //      cout << arr[i] << "+++++++++++\n";
        }

        int len = 0;
       // int count = 0;
        // for (vector<string>::iterator it = keyval.begin(); it != keyval.end(); it++) {
        for(  int i = 0; i < index; i++) {
            string output;
            output = keyval[i];
            int count = 0;
            len = output.length();
         //   cout << len << "len is !!!!!!!!\n";
            string out[line2];
            for (int q = 0; q < line2; q++) {
                if (len <= arr[q].length()) {
         //          cout << output << "======" << arr[q].substr(0, len) << "====\n";
                   //cout << output << arr[q].substr(0, len)<< "=========================\n";

                    if ( output == arr[q].substr(0, len)) {
           //         cout << output << "=============\n";
                    //reverse(arr[q].rbegin(), arr[q].rend());
                    out[count] = arr[q];
                    count++;
                    }
                }
            }
       //     cout << output << count << "========\n";
            if ( count >= k) {
               // count = 0;
                    // string output = *it;
                    reverse(output.rbegin(), output.rend());
                    outputfile << output;
                    outputfile << " -> [";

                for ( int p = 0; p < count; p++) {
                    reverse(out[p].rbegin(), out[p].rend());
                }
                r.Qsort(out, 0, count-1);
                
                for ( int o = 0; o < count-1; o++) {             
                    outputfile << out[o] << ", ";
                 //   reverse(out[o].rbegin(), out[o].rend());
                    out[o].clear();
                }
                outputfile << out[count-1] << "]\n";
            }
        }


                // for ( int c = 0; c < lenmax; c++) {
                //    // cout << "check2\n";
                //     for ( int b = 0; b < line2; b++) {
                //     //    cout << "check3\n";
                //     ap = arr[b].substr(0, c+1);
                //    // cout << "check4\n";
                //     // if ( ap == "debba") {
                //     //     cout << "check\n";
                //     // }
                //     if ( keyval.size() == 0) {
                //         keyval.push_back(ap);
                //     }
                //     else {
                //         for (vector<string>::iterator it = keyval.end()-1; it >= keyval.begin(); it--) {
                //        // cout << "check5\n";
                //         if ( *it == ap) {
                //          //   cout << "check3\n";
                //             exist = 1;
                //             break;
                //         }
                //     }
                // //    cout << "check6\n";
                //     if ( c > arr[b+1].length()) {
                //     //    cout << "check7\n";
                //         b++;
                //     }

                //     if ( exist == 1) {
                //         exist = 0;
                //     }
                //     else {
                //          reverse(ap.rbegin(), ap.rend());
                //          if ( ap < *keyval.begin()) {
                //             keyval.insert(keyval.begin(), ap);
                //          }
                //          else {
                //              //int cou = 0;
                //              for (vector<string>::iterator it = keyval.begin(); it != keyval.end(); ++it) {
                //                  if ( *it < ap ) {
                //                       keyval.insert(it, ap);
                //                      break;
                //                  }
                //                  //cou++;
                //              }
                //              //keyval.insert(cou, &ap);
                //          }
                //     }
                //     }
                    // for (vector<string>::iterator it = keyval.end()-1; it >= keyval.begin(); it--) {
                    //     cout << "check5\n";
                    //     if ( *it == ap) {
                    //         cout << "check3\n";
                    //         exist = 1;
                    //         break;
                    //     }
                    // }
                    // cout << "check6\n";
                    // if ( c > arr[b+1].length()) {
                    //     cout << "check7\n";
                    //     b++;
                    // }

                    // if ( exist == 1) {
                    //     exist = 0;
                    // }
                    // else {
                    //      reverse(ap.rbegin(), ap.rend());
                    //      if ( ap < *keyval.begin()) {
                    //         keyval.insert(keyval.begin(), ap);
                    //      }
                    //      else {
                    //          //int cou = 0;
                    //          for (vector<string>::iterator it = keyval.begin(); it != keyval.end(); ++it) {
                    //              if ( *it < ap ) {
                    //                   keyval.insert(it, ap);
                    //                  break;
                    //              }
                    //              //cou++;
                    //          }
                    //          //keyval.insert(cou, &ap);
                    //      }
                    // }
       
            //     }

            // }
        //cout << "check2\n";
        // cout << keyval.size() << "!!!!!\n";
        // for ( int a = 0; a < index; a++) {
        //     reverse(keyval[a].rbegin(), keyval[a].rend());
        //     if ( keyval[a] == "debba") {
        //         cout << "check\n";
        //     }
        // }
        //cout << "check3\n";
        // for(int g = 0; g < keyval.size()-1; ++g)
        //     for( int h = g+1; h < index; ++h)
        // {
        //   if(keyval[g] > keyval[h])
        //   {
        //     string temp = keyval[g];
        //     keyval[g] = keyval[h];
        //     keyval[h] = temp;
        //   }
        // }

        // for ( int a = 0; a < index; a++) {
        //     reverse(keyval[a].rbegin(), keyval[a].rend());
        // }

        // for (vector<string>::iterator it = keyval.begin(); it != keyval.end(); ++it) {
        //     int len = (*it).length();
        //     string out[line2];
        //     int count = 0;
        //     for ( int  q = 0; q<line2; q++) {
        //         reverse(arr[q].rbegin(), arr[q].rend());
        //         if ( *it == arr[q].substr(arr[q].length()-len,arr[q].length())) {
        //             out[count] = arr[q];
        //             count++;
        //         }
        //     }
        //         if ( count >= k) {
        //         for(int g = 0; g < count-1; ++g)
        //     for( int h = g+1; h < count; ++h)
        // {
        //   if(out[g] > out[h])
        //   {
        //     string temp = out[g];
        //     out[g] = out[h];
        //     out[h] = temp;
        //   }
        // }
        //           string output = *it;
        //             outputfile << output;
        //             outputfile << " -> [";
        
        //         for ( int o = 0; o < count-1; o++) {             
        //             outputfile << out[o] << ", ";
        //             out[o].clear();
        //         }
        //         outputfile << out[count-1] << "]\n";
                
        // }
        // }



        // for ( int p = 0; p < keyval.size(); p++) {
        //     int len = keyval[p].length();
        //     string out[line2];
        //     int count = 0;
        //     for ( int q = 0; q < line2; q++) {
        //         if ( keyval[p] == arr[q].substr(0,len)) {
        //             out[count] = arr[q];
        //             count++;
        //         }
        //     }
        //         if ( count >= k) {
        //         for ( int s = 0; s< count; s++) {
        //             reverse(out[s].rbegin(), out[s].rend());        
        //         }
        //             for(int g = 0; g < count-1; ++g)
        //     for( int h = g+1; h < count; ++h)
        // {
        //   if(out[g] > out[h])
        //   {
        //     string temp = out[g];
        //     out[g] = out[h];
        //     out[h] = temp;
        //   }
        // }
        //             reverse(keyval[p].rbegin(), keyval[p].rend());
        //             for ( int r = 0; r < len; r++) {
        //                 outputfile << keyval[p].at(r);
        //             }
        //             outputfile << " -> [";
        
        //         for ( int o = 0; o < count-1; o++) {             
        //             outputfile << out[o] << ", ";
        //             out[o].clear();
        //         }
        //         outputfile << out[count-1] << "]\n";
                
        //         }

            
        // }

    }
}


void printPostorder(node* node) 
{ 
    if (node == NULL) 
        return; 
    printPostorder(node->left); 
    printPostorder(node->right);
    outputfile << node->key << " ";
}


void traverse(node* root)
{
    queue<node*> q;
    if (root == NULL) {
        return;
    }
    for (q.push(root); !q.empty(); q.pop()) {
        const node * const temp_node = q.front();
        outputfile << temp_node->key <<" ";

        if (temp_node->left) {
            q.push(temp_node->left);
        }
        if (temp_node->right) {
            q.push(temp_node->right);
        }
    }
}

void levelOrderHelper(Nod *root) 
{ 
    if (root == NULL) 
        return; 
  
    queue<Nod *> q; 
    q.push(root); 
  
    while (!q.empty()) 
    { 
        Nod *temp = q.front();
        outputfile << temp->key << " "; 
        q.pop(); 
  
        if (temp->left != NULL) 
            q.push(temp->left); 
  
        if (temp->right != NULL) 
            q.push(temp->right); 
    } 
}

void read_part_2(ifstream &inputfile, ofstream &outputfile)
{
    //handle input, output from file
    //cout << "get into part 2!!!!!!!!\n";
    int line;
    inputfile >> line;
    string fun;
    node *ro = NULL;
    node *temp = NULL;
    Node *n = new Node(ro);
    BinarySearchTree *b = new BinarySearchTree();
     for ( int i = 0; i < line; i++) {
         inputfile >> fun;
         if ( fun == "insert") {
             check = 0;
            // cout << i << "======insert !!!!!!!!\n";
             int num;
             inputfile >> num;
             n->insertKey(n->root, num);
           //  cout << "root is " << n->root->key << " ===============\n";
           // printPostorder(n->root);
             
         }
         else if ( fun == "delete") {
             check = 0;
            // cout << i << "======delete !!!!!!!!\n";
             int num;
             inputfile >> num;
             temp = n->deleteKey(n->root, num);
             if ( temp == NULL ) {             
                 outputfile << "deletion failed\r\n";
             }
             else {
                // printPostorder(n->root);
                outputfile << "deleted\r\n";
                 
             }
         }
         else if ( fun == "height") {
             check = 0;
           // cout << i << "======heigth !!!!!!!!\n";
             int num;
             inputfile >> num;
             int out = n->height(n->root, num);
             if ( out < 0 ) {
                 outputfile << "none\r\n";
             }
             else {
                 outputfile << out << "\r\n";
             }
         }
         else if ( fun == "search") {
             check = 0;
          // cout << i << "======search !!!!!!!!\n";
              int num;
              inputfile >> num;
              int out = n->searchKey(n->root, num);
              if ( out == 0) {
                 outputfile << "not found\r\n";
             }
             else {
                 outputfile << "found\r\n";
             }
         }
         else if ( fun == "range") {
             check = 0;
        //    cout << i << "======range !!!!!!!!\n";
            int num1;
            inputfile >> num1;
            int num2;
            inputfile >> num2;
            int out = n->rangeSum(n->root, num1, num2);
            if ( out == 0) {
                outputfile << "none\r\n";
            }
            else {
                outputfile << out << "\r\n";
            }
         }
         else if ( fun == "postorder") {
             check = 0;
             if (n->root == NULL) {
                 outputfile << "none\r\n";
             }
             else {
                 printPostorder(n->root);
                 outputfile << "\r\n";
             }
         }
         else if ( fun == "levelorder") {
             if (check == 0) {
                 if (n->root == NULL) {
                 outputfile << "none\r\n";
             }
             else {
                 traverse(n->root);
                 outputfile << "\r\n";
             }
             }
             else {
                 if (b->root1 != NULL) {
            //     cout << i << b->root1->key << " =====================\n";
             }
             if (b->root1 == NULL) {
                 outputfile << "none\r\n";
             }
             else {
                 levelOrderHelper(b->root1);
                 outputfile << "\r\n";
                }
             }
             
         }
         else if ( fun == "lca") {
             check = 0;
          //   cout << i << "--------------------------------\n";
            int num1;
            inputfile >> num1;
            int num2;
            inputfile >> num2;
            int out = n->LCA(n->root, num1, num2);
         //   cout << out << "checkcheckcheck\n";
            if ( out < 0) {
                outputfile << "none\r\n"; 
           //     cout << out << "1111checkcheckcheck\n";
            }
            else {
                outputfile << out << "\r\n";
         //       cout << out << "2222checkcheckcheck\n";
            }
         }
         else if ( fun == "ceil") {
             check = 0;
             int num;
            inputfile >> num;
            int out = n->ceil(n->root, num);
            if ( out == 0) {
                outputfile << "none\r\n"; 
            }
            else {
                outputfile << out << "\r\n";
            }
         }
         else if ( fun == "floor") {
             check = 0;
             int num;
            inputfile >> num;
            int out = n->floor(n->root, num);
            if ( out == 0) {
                outputfile << "none\r\n"; 
            }
            else {
                outputfile << out << "\r\n";
            }
         }
         else if (fun == "dist") {
             check = 0;
             int num1;
            inputfile >> num1;
            int num2;
            inputfile >> num2;
            int out = n->dist(n->root, num1, num2);
            if (out < 0) {
                outputfile << "none\r\n"; 
            }
            else {
                outputfile << out << "\r\n";
            }
         }
         else if (fun == "insertRB") {
             check = 1;
        //         if (b->root1 != NULL) {
        //    //      cout << i << b->root1->key << " =====================\n";
        //      }
            int num;
            inputfile >> num;
            b->insert(num);
            // levelOrderHelper(b->root1);
            // outputfile << "\r\n";
         }
         else if (  fun=="Bheight") {
             check = 1;
    //          if (b->root1 != NULL) {
    // //             cout << i << b->root1->key << " =====================\n";
    //          }
            int num;
            inputfile >> num;
            Nod* tem = b->finddata(b->root1, num);
            int out = b->Bheight(tem, num);
            if ( tem->color == BLACK) {
                out--;
            }
            out++;
            if ( out == 0) {
                outputfile << "none\r\n";
            }
            else {
                outputfile << out << "\r\n";
            }
            b->count = 0;
         }


     }
    
}

int main(int argc, char *argv[])
{
    //Read in the test case
    if(argc==3){
        inputfile.open(argv[1]);
        outputfile.open(argv[2]);
    }
    else{
        cout<<"Not enough arguments"<<endl;
    }

    string str;

    getline(inputfile, str);
    int part;
    stringstream convert(str);
    convert >> part;

    switch(part)
    {
        case 1:
            read_part_1(inputfile,outputfile);
            break;
        case 2:
            read_part_2(inputfile,outputfile);
            break;
    }


	return 0;
}
