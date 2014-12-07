/*****
* Author   : brinkmwj
* Date     : 2009-11-06
* Sources  : All code is original
*/
#include <iostream>
#include "Graph.h"
#include <stack>

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
	this->numNodes = numNodes;
}

int Graph::getCost(int node1, int node2){
	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++)	{
		if (adjList[node1].edgeList[i].dest == node2)	{
			return adjList[node1].edgeList[i].cost;
		}
	}
	return -1;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	if (cost < 0)
		throw std::string("Cost cannot be less than 0");
	if (node1 < 0 || node1 > adjList.size())
		throw std::string("Node 1 was too big or was below 0");
	if (node2 < 0 || node1 > adjList.size())
		throw std::string("Node 2 was too big or was below 0");

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++)	{
		if (adjList[node1].edgeList[i].dest == node2)	{	//node already exists
			adjList[node1].edgeList[i].cost = cost;

			for (unsigned int j = 0; j < adjList[node2].edgeList.size(); j++)	{
				if (adjList[node2].edgeList[j].dest == node1)	{
					adjList[node2].edgeList[j].cost = cost;
				}
				return;
			}
		}
	}

	adjList[node1].edgeList.push_back(Edge(cost, node2));
	adjList[node2].edgeList.push_back(Edge(cost, node1));
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	if (node1 < 0 || node1 > adjList.size())
		throw std::string("Node 1 was too big or was below 0");
	if (node2 < 0 || node1 > adjList.size())
		throw std::string("Node 2 was too big or was below 0");

	for (unsigned int i = 0; i < adjList[node1].edgeList.size(); i++)	{
		if (adjList[node1].edgeList[i].dest == node2)	{
			adjList[node1].edgeList.erase(adjList[node1].edgeList.begin() + i);

			for (unsigned int j = 0; j < adjList[node2].edgeList.size(); j++)	{
				if (adjList[node2].edgeList[j].dest == node1)	{
					adjList[node2].edgeList.erase(adjList[node2].edgeList.begin() + j);
					return;
				}
			}

		}
	}
}
/*
DFS - Depth First Search
	->input: statring node #
	->we will have two data structures to help
		->open list : list of vertices we know about, but haven't visited
		->closed list : list of vertices already visited

	1. put start node in open list, which is ***stack***
	2. while open list no empty
		3. take item from open list, call it u
		4. visit it(do something)
		5. get neighborlist of u
		6. for all nodes in that neighbor list
			7. add to open list, unless it is already there, or already in closed list
	->keep going as long as you can, when you get stuck go back and go down another path
	->spanning tree : connects all nodes of the graph together
*/
void Graph::DFS(int node)	{
	if (node < 0)
		throw std::string("Node is not in the graph");

	std::stack<int> open;
	std::vector<int> closed;
	closed.resize(numNodes);

	open.push(node);
	closed[node] = 0; //not closed


	while (!open.empty())	{
		int currentNode = open.top();
		std::cout << "Visited: " << currentNode << std::endl;
		open.pop();
		closed[currentNode] = 1; //mark closed

		for (int i = 0; i < adjList[currentNode].edgeList.size(); i++)	{
			if (closed[adjList[currentNode].edgeList[i].dest] == 0)	{
				open.push(adjList[currentNode].edgeList[i].dest);
			}
		}
	}
}
