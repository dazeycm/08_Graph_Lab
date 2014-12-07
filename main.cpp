#include "Graph.h"
#include <iostream>

void testGraph(){
	Graph g(10);
	g.addEdge(0,1,50);
	if(g.getCost(1,0) != 50 || g.getCost(0,1) != 50){
		std::cout << "ERROR: Expected edge cost of 50, got " << g.getCost(1,0) << std::endl;
		exit(1);
	} else {
		std::cout << "SUCCESS: Got the right edge cost" << std::endl;
	}

	if(g.getCost(2,3) != -1){
		std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(2,3) << std::endl;
		exit(1);
	} else {
		std::cout << "SUCCESS: Got the right edge cost for non-existent edge" << std::endl;
	}

	g.removeEdge(1,0);
	if(g.getCost(0,1) != -1 || g.getCost(1,0) != -1){
		std::cout << "ERROR: Expected edge cost of -1, got " << g.getCost(1,0) << std::endl;
		exit(1);
	} else {
		std::cout << "SUCCESS: Got the right edge cost for removed edge" << std::endl;
	}

}

void testDFS()	{
	Graph g(10);
	g.addEdge(1, 2, 0);
	g.addEdge(3, 2, 0);
	g.addEdge(2, 4, 0);
	g.addEdge(5, 6, 0);
	g.addEdge(7, 6, 0);
	g.addEdge(4, 6, 0);
	g.DFS(4);
	std::cout << "Finished DFS" << std::endl;
	g.BFS(4);
}

int main(){
	testGraph();
	testDFS();
	return 0;
}
