/*****
* Author   : brinkmwj
* Date     : 2009-11-06
* Sources  : All code is original
* 
* This class uses the adjacency list representation of graphs, but 
* using vector for both the main array and for the actual adjacency "lists"
*/

/*
	Graph Traversals
	================
	Goal: Visit each node exactly once, and "do something"
	n = number of nodes
	m = number of edges

	O(n + m) when doing adjacency list
	
	DFS - Depth First Search
		-> input: statring node #
		-> we will have two data structures to help
			-> open list:	list of vertices we know about, but haven't visited
			-> closed list:	list of vertices already visited
		
		1. put start node in open list, which is ***stack***
		2. while open list no empty
			3. take item from open list, call it u
			4. visit it (do something)
			5. get neighborlist of u 
			6. for all nodes in that neighbor list
				7. add to open list, unless it is already there, or already in closed list
		-> keep going as long as you can, when you get stuck go back and go down another path
		-> spanning tree: connects all nodes of the graph together


	BFS - Breadth First Search
		-> input: statring node #
		-> we will have two data structures to help
			-> open list:	list of vertices we know about, but haven't visited
			-> closed list:	list of vertices already visited

		1. put start node in open list, which is ***queue***
		2. while open list no empty
			3. take item from open list, call it u
			4. visit it (do something)
			5. get neighborlist of u 
			6. for all nodes in that neighbor list
				7. add to open list, unless it is already there, or already in closed list
		-> keep going as long as you can, when you get stuck go back and go down another path
		-> spanning tree: connects all nodes of the graph together


	Djikstra - Djikstra's Algorithm
		-> input: statring node #
		-> we will have two data structures to help
			-> open list:	list of vertices we know about, but haven't visited
			-> closed list:	list of vertices already visited
	{ this stuff below isn't too accurate
		1. put start node in open list, which is ***priority queue***
		2. while open list no empty
			3. take item from open list, call it u
			4. visit it (do something)
			5. get neighborlist of u             
			6. for all nodes in that neighbor list
				7. add to open list, unless it is already there, or already in closed list
		-> keep going as long as you can, when you get stuck go back and go down another path
		-> spanning tree: connects all nodes of the graph together
	} 
*/


#include <vector>

//The edge class has only a cost and a destination.
class Edge{
public:
	Edge(double c, int d){cost = c; dest = d;};
	Edge(){cost = -1; dest = -1;};

	double cost;
	int dest; //Destination node number
};

class Node{
public:
	std::vector<Edge> edgeList;
};

//A Graph is just a list of nodes, where each node is responsible
// for keeping a list of the edges adjacent to itself.
class Graph{
public:

	//You will need to resize the adjList before you can use it
	Graph(unsigned int numVertices);

	//Return the cost of the edge from node1 to node2. If there
	// is no edge, return -1.
	int getCost(int node1, int node2);

	//Add an edge from node1 to node2, and from node2 to node1, with
	// the given cost. If the cost is < 0, throw a string exception.
	// If the edge already exists, just update the cost
	void addEdge(int node1, int node2, double cost);

	//Remove the edge from node1 to node2, and also from node2 to node1.
	// If there are no such edges, then don't do anything.
	void removeEdge(int node1, int node2);

	//DFS
	void DFS(int node);

private:
	int numNodes;
	std::vector<Node> adjList;	
};

