#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	private:
		// int numCities;
		// int numRoutes;
		string *cities;
		
	public:
		int connected;
		bool *visited;
		bool *mstSet;
		vector<int> tree;
		int disct;
		stack<int> st; 
		vector<string> arr;
		vector<list<pair<int, double>>> adjacencyList;
		int numCities;
		int numRoutes;
		vector<double> dist;
		bool *sptSet;
		vector<int> disc;
		vector<int> evaFun;
		vector<int> findEdges();
		double shortest;
		vector<int> path;
		vector<int> parent;
		vector<double> key;
		stack<int> par;
		Graph(int, int);
		void addRoute(string, string, double);
		void doDFS();
		void DFS(int);
		int getIndex(string);
		void analyseGraph();	
		void primMST(int);
		int minKey();	
		double findCost(string, string);
		int minDistance();
		void dijkstra(int);

};

#endif
