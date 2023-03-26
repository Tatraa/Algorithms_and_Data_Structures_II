#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.h"


int main() {
    Graph G(5);

    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(0, 4);

    set<int> out0 = G.outConnections(0);
    cout << "Wszystkie wierzchołki do których istnieje połączenie z wierzchołka 0: ";
    for (int v : out0) {
        cout << v << " ";
    }
    cout << endl;

    set<int> in4 = G.inConnections(4);
    cout << "Wszystkie wierzchołki od których istnieje połączenie z wierzchołka 4: ";
    for (int v : in4) {
        cout << v << " ";
    }
    cout << endl;

    set<int> all2 = G.allConnections(2);
    cout << "Wszystkie wierzchołki połączone z wierzchołka 2: ";
    for (int v : all2) {
        cout << v << " ";
    }
    cout << endl;

    int* dist = BFS(G, 0);
    cout << "Dystanse od wierzchołka 0 do poszczególnych wierzchołków: ";
    for (int i = 0; i < G.getNumVertices(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    delete[] dist;

    cout << "Czy wierzchołki 3 i 4 są połączone krawędzią?: " << G.hasEdge(3, 4) << endl;

    cout << "Usuwanie krawędzi między wierzchołkami 3 i 4..." << endl;
    G.removeEdge(3, 4);
    cout << "Czy wierzchołki 3 i 4 są połączone krawędzią?: " << G.hasEdge(3, 4) << endl;
    return 0;
}
