/*****
* Author   : brinkmwj
* Date     : 2009-11-06
* Sources  : All code is original
*/
#include "Graph.h"

Graph::Graph(unsigned int numNodes){
	adjList.resize(numNodes);
	for (int i = 0; i < numNodes; i++)	{
		adjList[i].edgeList.resize(numNodes);
	}
}

int Graph::getCost(int node1, int node2){
	Node node = adjList.at(node1);
	Edge edge = node.edgeList[node2];
	if (edge.dest == -1)							//this reminds me of hashtables
		return -1;									//the edge doesn't exist.. I could just use the cost here and not have the extra bloat in addEdge, but the dest exists in edge, so I guess I should use it
	return edge.cost;
}

//Add an edge from node1 to node2, and from node2 to node1, with
// the given cost. If the cost is < 0, throw a string exception.
void Graph::addEdge(int node1, int node2, double cost){
	Node* addTo = &adjList[node1];				//pointer to node containing edgelist we want
	addTo->edgeList[node2].cost = cost;			//since the index of the edgelist is the destination, I don't think we need to update the destination?
	addTo->edgeList[node2].dest = node2;		//needed so getCost doesn't think there isn't an edge here

	addTo = &adjList[node2];
	addTo->edgeList[node1].cost = cost;
	addTo->edgeList[node1].dest = node1;
}

//Remove the edge from node1 to node2, and also from node2 to node1.
// If there are no such edges, then don't do anything.
void Graph::removeEdge(int node1, int node2){
	Node* toRemove = &adjList[node1];
	toRemove->edgeList[node2].cost = -1;
	toRemove->edgeList[node2].dest = -1;

	toRemove = &adjList[node2];
	toRemove->edgeList[node1].cost = -1;
	toRemove->edgeList[node1].dest = -1;
}
