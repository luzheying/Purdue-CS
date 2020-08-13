#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "graph.h"
#include <vector>
#include <list>
#include <utility>
#include <stack>
#include <algorithm> 
#include <iomanip>
#define INFI 1000000

 
using namespace std;
 
     ifstream inputfile;
     ofstream outputfile;
     vector<string> outP;

 // Part 1 : Find the connected components and the bridge
void part1(ifstream &inputfile, ofstream &outputfile)
{
    int num1;
    inputfile >> num1;
    int num2;
    inputfile >> num2;
    Graph *g = new Graph(num1, num2);
    for (int i = 0; i < num2;i++) {
        string str1;
        string str2;
        double weight;
        inputfile >> str1;
        inputfile >> str2;
        inputfile >> weight;
        g->addRoute(str1,str2,weight);
    }
    
    g->doDFS();
    vector<int> v;
    v = g->findEdges();
    // int c = 0;
    int count = g->connected;
    outputfile << count << "\n";
    int size = v.size();

    if( size != 0) {
        vector<string> out;
        outputfile << size/2 << "\n";
        for (int i = 0; i<size-2; i++) {
           // c++;
            //outputfile << g->arr[v[i]];
            if ( i%2 == 0) {
                out.clear();
               // outputfile << "\n";
                out.push_back(g->arr[v[i]]);
            }
            else {
                out.push_back(g->arr[v[i]]);
                sort(out.begin(),out.end());
                outputfile << out[0] << " " << out[1] << "\n";
            }
    }
    out.clear();
    out.push_back(g->arr[v[size-2]]);
    out.push_back(g->arr[v[size-1]]);
    sort(out.begin(),out.end());
    outputfile << out[0] << " " << out[1];
    out.clear();
    }
    else {
         outputfile << size/2;
    }



}

 // Part 2 :  Find a ticket using Dijkstra	
void part2(ifstream &inputfile, ofstream &outputfile)
{
    int num1;
    inputfile >> num1;
    int num2;
    inputfile >> num2;
    Graph *g = new Graph(num1, num2);
    for (int i = 0; i < num2;i++) {
        string str1;
        string str2;
        double weight;
        inputfile >> str1;
        inputfile >> str2;
        inputfile >> weight;
        g->addRoute(str1,str2,weight);
    }
    int count = 0;
    string strS;
    string strD;
    while(strS!="END") {
        if (count!=1 && count%2!=0) {
            outputfile << "\n";
        }
        count++;
        if (count % 2 != 0) {
            inputfile >> strS; 
        }
        else {
            inputfile >> strD;
            double out = g->findCost(strS,strD);
             
            if (out == 0) {
                outputfile << "not possible";
            }else {
                stack<int> s;
                vector<int> p = g->path;
                for(int i = 0; i < p.size() ; i++) {
                }
                int tem1 = g->getIndex(strS);
                int tem2 = g->getIndex(strD);
                while(tem1!=tem2) {
                    s.push(tem2);
                    tem2 = p[tem2];
                }
                s.push(tem1);
                int outp;
                while(!s.empty()){
                    outp = s.top();
                    s.pop();
                    outputfile << g->arr[outp] << " ";
                }
                outputfile << fixed << setprecision(2) << out;
            }
        }
    }
    
}

int c = 0;
void eulerianTour(vector<int> parent,int root, Graph *g) {
    c++;
    vector<int> p = parent;
    vector<string> children;
    int r = root;
    Graph *gr = g;
    if (p[r] == -2) {
        return;
    }
    p[r] = -2;
    outputfile << gr->arr[r];
    if ( c!=g->numCities) {
        outputfile << "\n";
    }
    for ( int j = 0; j < p.size(); j++) {
        if (p[j] == r) {
            children.push_back(gr->arr[j]);
        }
    }
    sort(children.begin(),children.end());
    for ( int k = 0; k < children.size();k++) {
         eulerianTour(p, g->getIndex(children[k]), gr);
    }
}


 // Part 3 :Try to do a tour of all cities 
void part3(ifstream &inputfile, ofstream &outputfile)
{
    int num1;
    inputfile >> num1;
    int num2;
    inputfile >> num2;
    outP.resize(num1);
    Graph *g = new Graph(num1, num2);
    for (int i = 0; i < num2;i++) {
        string str1;
        string str2;
        double weight;
        inputfile >> str1;
        inputfile >> str2;
        inputfile >> weight;
        g->addRoute(str1,str2,weight);
    }

    string str;
    inputfile >> str;
    int root = g->getIndex(str);
    g->primMST(root);
    vector<int> parent = g->parent;
    int count = 0;
    for (int i = 0; i < parent.size();i++) {
        if (parent[i] == INFI) {
            count++;
        }
    }
    if (count != 0) {
        outputfile << "not possible";
    }
    else {
         eulerianTour(parent,root,g);
    }
   
}
 
 int main(int argc, char *argv[])
 {
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


	 if(part == 1) part1(inputfile, outputfile);
	 else if(part == 2)  part2(inputfile, outputfile);
	 else if(part == 3) part3(inputfile, outputfile);

	 return 0;
 }
