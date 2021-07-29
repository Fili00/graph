#include "graph.h"

using namespace graph;

struct graph::halfEdgeVertex{
    vertexNode* vertexPtr;
    Weight weight;
    halfEdgeVertex* next;
};

struct graph::vertexNode{
    Label label;
    halfEdgeVertex* adjList;
    vertexNode* next;
    bool visited;
};

/*******************************************************************************************************/
// Aux
/*******************************************************************************************************/
Graph getNode(const Label l, const Graph& g){
    for(Graph tmp = g; !isEmpty(tmp); tmp = tmp -> next){
        if(tmp -> label == l)
            return tmp;
    }
    return emptyGraph;
}

adjVertex createAdjVertex(Weight w, adjVertex adj, const Graph& to){
    adjVertex tmp = new halfEdgeVertex;
    tmp -> next = adj;
    tmp -> vertexPtr = to;
    tmp -> weight = w;
    return tmp;
}

int nodeDegree(Graph node){
    if(isEmpty(node))
        return -1;
    int count = 0;
    for(adjVertex tmp = node -> adjList; tmp != emptyAdjVertex; tmp = tmp -> next)
        count++;
    return count;
}

void setFalse(const Graph& g){
    Graph tmp = g;
    while(!isEmpty(tmp)){
        tmp -> visited = false;
        tmp = tmp -> next;
    }
}

/*******************************************************************************************************/
// Graph
/*******************************************************************************************************/

// Restituisce il grafo vuoto
Graph graph::createEmptyGraph()
{
    return emptyGraph;
}

// Aggiunge nuovo vertice con etichetta la stringa. Fallisce se gia' presente
bool graph::addVertex(Label l, Graph& g) {
    if(!isEmpty(getNode(l, g)))
        return false;
    Graph tmp = new vertexNode;
    tmp -> label = l;
    tmp -> adjList = emptyAdjVertex;
    tmp -> visited = false;
    tmp -> next = g;
    g = tmp;
    return true;
}

// Aggiunge un arco di peso "w" tra i nodi con etichetta "f" e "t". Fallisce se esiste gia' l'arco
// se i nodi non esistono nel grafo e se si tenta di inserire un arco tra un nodo ed esso stesso
bool graph::addEdge(Label from, Label to, Weight w, const Graph& g) {
    Graph nodeFrom = getNode(from, g);
    Graph nodeTo = getNode(to, g);
    if(isEmpty(nodeFrom) || isEmpty(nodeTo) || areAdjacent(from, to, g))
        return false;
    nodeFrom -> adjList = createAdjVertex(w, nodeFrom -> adjList, nodeTo);
    return true;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g)
{
    return g == emptyGraph;
}

// Ritorna il numero di vertici del grafo
int graph::numVertices(const Graph& g){
    Graph tmp = g;
    int count=0;
    while(!isEmpty(tmp)){
        tmp = tmp -> next;
        count++;
    }
    return count;
}

// Ritorna il numero di archi del grafo
int graph::numEdges(const Graph& g){
    int count = 0;
    for(Graph tmp = g; !isEmpty(tmp); tmp = tmp -> next)
        count += nodeDegree(tmp);
    return count;
}

// Calcola e ritorna il grado del nodo. Se fallisce (il nodo non esiste)
// restituisce -1
int graph::degree(Label l, const Graph& g) {
    return nodeDegree(getNode(l, g));
}

// Verifica se esiste un arco da v1 a v2
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
    Graph tmpGraph = getNode(v1, g);
    if(isEmpty(tmpGraph))
        return false;
    for(adjVertex tmp = tmpGraph -> adjList; tmp != emptyAdjVertex; tmp = tmp -> next)
        if(tmp -> vertexPtr -> label == v2)
            return true;
    return false;
}

// Restituisce la lista di adiacenza di un vertice
std::list<Label> graph::adjacentList(Label v1, const Graph& g) {
    std::list<Label> l;
    Graph tmpGraph = getNode(v1, g);
    if(isEmpty(tmpGraph))
        return l;
    for(adjVertex tmp = tmpGraph -> adjList; tmp != emptyAdjVertex; tmp = tmp -> next)
        l.push_front(tmp -> vertexPtr -> label);
    return l;
}

bool graph::changeLabel(Label oldLabel, Label newLabel, const Graph &g) {
    Graph tmp = getNode(oldLabel, g);
    if(isEmpty(tmp))
        return false;
    tmp -> label = newLabel;
    return true;
}

std::list<std::pair<Label, Label> > graph::allEdge(const Graph& g){
    std::list<std::pair<Label, Label> > l;
    for(Graph tmp = g; !isEmpty(tmp); tmp = tmp -> next)
        for(adjVertex  adj = tmp -> adjList; adj != emptyAdjVertex; adj = adj -> next)
            l.push_back(std::make_pair(tmp -> label, adj -> vertexPtr -> label));
    return l;
}

/*******************************************************************************************************/
// Stampa il grafo
void printGraph(const graph::Graph& g) {
    Graph tmpGraph = g;
    while(!isEmpty(tmpGraph)){
        adjVertex tmpAdj = tmpGraph -> adjList;
        cout<<tmpGraph -> label<<":"<<endl;
        while(tmpAdj != emptyAdjVertex){
            cout<<"\t"<<tmpAdj -> vertexPtr -> label<<" "<<tmpAdj -> weight<<endl;
            tmpAdj = tmpAdj -> next;
        }
        tmpGraph = tmpGraph -> next;
    }
}
