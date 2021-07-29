//
// Created by Filippo Siri on 29/07/21.
//

#include "graph.h"
#include <iostream>
using namespace std;


int main(){
    graph::Graph g = graph::createEmptyGraph();
    graph::addVertex("A", g);
    graph::addVertex("B", g);
    graph::addVertex("C", g);
    graph::addVertex("D", g);
    graph::addVertex("A", g);
    graph::addEdge("A","B",1,g);
    graph::addEdge("A","B",2,g);
    graph::addEdge("A","C",3,g);
    graph::addEdge("A","D",4,g);
    graph::addEdge("D","A",4,g);
    graph::addEdge("D","Q",4,g);
    graph::addEdge("Z","A",4,g);
    printGraph(g);
    cout<<graph::numVertices(g)<<" "<<graph::numEdges(g)<<endl;
    cout<<graph::degree("A",g)<<" "<<graph::degree("B",g)<<" "<<graph::degree("q",g)<<endl;
    cout<<graph::areAdjacent("A","B",g)<<" "<<graph::areAdjacent("B","A",g)<<" "<<graph::areAdjacent("Q","A",g)<<" "<<graph::areAdjacent("A","Q",g)<<endl;
    return 0;
}