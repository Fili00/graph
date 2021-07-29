#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <list>
#include <utility>

using namespace std;

namespace graph {

    typedef string Label;
    typedef int Weight;

    struct vertexNode; // da definire nel file graph.cpp
    struct halfEdgeVertex;

    typedef vertexNode *Graph; // un grafo e' identificato dal puntatore al primo vertice inserito
    typedef halfEdgeVertex *adjVertex;

    const Graph emptyGraph = NULL;
    const adjVertex emptyAdjVertex = NULL;

// createEmptyGraph restituisce il grafo vuoto
    Graph createEmptyGraph();

// Aggiunge nuovo vertice con etichetta la stringa. Fallisce se gia' presente
    bool addVertex(Label, Graph &);

// Aggiunge nuovo arco tra i due nodi con etichette le due stringe e peso
// l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente.
    bool addEdge(Label, Label, Weight, const Graph &);

// Restituisce true se il grafo e' vuoto, false altrimenti
    bool isEmpty(const Graph &);

// Ritorna il numero di vertici del grafo
    int numVertices(const Graph &);

// Ritorna il numero di archi del grafo
    int numEdges(const Graph &);

// Calcola e ritorna il grado del nodo. Se fallisce (il nodo non esiste)
// restituisce -1
    int degree(Label, const Graph &);

// Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
    bool areAdjacent(Label, Label, const Graph &);

// Ritorna la lista di adiacenza di un vertice
    std::list<Label> adjacentList(Label, const Graph &);

//Se esiste, cambia il label del nodo
    bool changeLabel(Label, Label, const Graph &g);

    std::list<std::pair<Label, Label> > allEdge(const Graph& );
}

/* Funzioni che non caratterizzano il TDD Graph, ma che servono per input/output */
//tree::Tree readFromFile(string);
void printGraph(const graph::Graph&);
