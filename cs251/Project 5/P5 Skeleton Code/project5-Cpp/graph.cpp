#include <iostream>
#include <string>
#include "graph.h"
#include <vector>
#include <list>
#include <utility>
#include <stack>

#define INFI 1000000



/*
	Graph class for use in Project 5.
	
	This provided code does not include any specific data structure
	for storing a graph, only a list of methods that will be called 
	from main. Based on the project handout and the lecture slides,
	select a method for storing the graph and implement it here.

*/

// Constructor for Graph

Graph::Graph(int Vertices, int routes) {
    adjacencyList.resize(Vertices + 1);
	numCities = Vertices;
	numRoutes = routes;
}

void Graph::addRoute(string str1, string str2, double weight) {
	int index1 = 0;
	int index2 = 0;
	int c1 = 0;
	int c2 = 0;
	int count = -1;
	if(arr.size()>0) {
		vector<string>:: iterator i;
    		for (i = arr.begin(); i != arr.end(); i++) {
				count++;
                if(*i == str1) {
					c1 = 1;
					index1 = count;
				}
				if(*i == str2) {
					c2 = 1;
					index2 = count;
				}
            }
	}
	if(c1 == 0){
		index1 = arr.size();
		arr.push_back(str1);
	}
	if(c2==0){
		index2 = arr.size();
		arr.push_back(str2);
	}
	adjacencyList[index1].push_back(make_pair(index2, weight));
	adjacencyList[index2].push_back(make_pair(index1, weight));
}

int Graph::getIndex(string str) {
	for (int i = 0; i<numCities;i++) {
		if(arr[i] == str) {
			return i;
		}
	}
	return -1;
}


void Graph::doDFS() {
	connected =0;

	disc.resize(numCities+1);
 	evaFun.resize(numCities+1);
	tree.resize(numCities+1);
	disct = 0;
    visited = new bool[numCities+1];
	for(int i = 0; i < numCities; i++) {
  		visited[i] = false;
	}

	for(int i = 0; i < numCities; i++) {
		if (!visited[i]) {
			connected++;
			tree[i] = i;
			DFS(i);
		}
	}

}

void Graph::DFS(int s)
{ 
    st.push(s); 
    while (!st.empty()) 
    { 
        s = st.top(); 
        st.pop();
        if (!visited[s])
        { 	
            visited[s] = true;
			disct++;
			disc[s] = disct;
			evaFun[s] = disct;
		}
        for (auto i = adjacencyList[s].rbegin(); i != adjacencyList[s].rend(); ++i){
			if (!visited[(*i).first]) {
				tree[(*i).first] = s;
				st.push((*i).first);
			}
			else {
					if((*i).first != tree[s]) {
						if(evaFun[s] > evaFun[(*i).first]) {
							int tem1 = (*i).first;
							int tem2 = s;
							while(tem1!=tem2) {
								if (evaFun[tem2] > evaFun[tem1]) {
									evaFun[tem2] = evaFun[tem1];
								}
								tem2 = tree[tem2];
							}
						}
					}
			}
		}
    } 
} 


vector<int> Graph::findEdges()
{
	vector<int> v;
	for( int j = 0; j < numCities+1;j++) {
		if (evaFun[j] > evaFun[tree[j]]) {
			v.push_back(tree[j]);
			v.push_back(j);
		}
    }
	return v;
}


int Graph::minDistance() 
{ 
   double min = (double)INFI;
    int min_index; 
   
   for (int v = 0; v < numCities; v++) 
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
   
   return min_index;
} 


double Graph::findCost(string source, string destination) {
	int strS = getIndex(source);
	int strD = getIndex(destination);
	path.resize(numCities);
	dijkstra(strS);
	if ( dist[strD] == (double)INFI) {
		return 0;
	}
	else {
		return dist[strD];
	}
}

void Graph::dijkstra(int src) 
{ 
     dist.resize(numCities);   
     sptSet = new bool[numCities];  
     for (int i = 0; i < numCities; i++) 
        dist[i] = (double)INFI, sptSet[i] = false;

     dist[src] = 0;
	 int u = -1;
	
     for (int count = 0; count < numCities-1; count++) 
     { 
       u = minDistance();
       sptSet[u] = true;
   
		for (auto i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i){
			if(!sptSet[(*i).first] && dist[u]!= (double)INFI && 
			dist[u]+(*i).second < dist[(*i).first]) {
				dist[(*i).first] = dist[u] + (*i).second;
		   			path[(*i).first] = u;
			}
		}
	 }
      
}

int Graph::minKey() 
{ 
	double min = (double)INFI, min_index; 
  
	for (int v = 0; v < numCities; v++) 
    	if (mstSet[v] == false && key[v] < min) 
       		min = key[v], min_index = v;
  
	return min_index; 
} 

void Graph::primMST(int root)
{ 
    parent.resize(numCities);  
    key.resize(numCities);  
    mstSet = new bool[numCities];
    for (int i = 0; i < numCities; i++) {
		 key[i] = INFI; 
		 mstSet[i] = false;
		 parent[i] = INFI;
	}
    key[root] = 0;    
    parent[root] = -1;
    for (int count = 0; count < numCities-1; count++)
    { 
        int u = minKey();
        mstSet[u] = true; 
  		for (auto i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i){
			if(!mstSet[(*i).first] && (*i).second < key[(*i).first]) {
				parent[(*i).first] = u;
				key[(*i).first] = (*i).second;
			}
		}
	}
}
  