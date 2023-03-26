#ifndef GRAPH_H
#define GRAPH_h

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Graph {
private:
    int numVert;
    vector<vector<int>> adjList;
public:
    Graph(int n) {
        numVert = n;
        adjList.resize(n);
    }

    void addEdge(int i, int j) {
        adjList[i].push_back(j);
    }

    void removeEdge(int i, int j) {
        for (int k = 0; k < adjList[i].size(); k++) {
            if (adjList[i][k] == j) {
                adjList[i].erase(adjList[i].begin() + k);
                break;
            }
        }
    }

    bool hasEdge(int i, int j) {
        for (int k = 0; k < adjList[i].size(); k++) {
            if (adjList[i][k] == j) {
                return true;
            }
        }
        return false;
    }

    set<int> inConnections(int i) {
        set<int> in;
        for (int j = 0; j < numVert; j++) {
            if (hasEdge(j, i)) {
                in.insert(j);
            }
        }
        return in;
    }

    set<int> outConnections(int i) {
        set<int> out;
        for (int j : adjList[i]) {
            out.insert(j);
        }
        return out;
    }

    set<int> allConnections(int i) {
        set<int> all;
        for (int j : outConnections(i)) {
            all.insert(j);
        }
        for (int j : inConnections(i)) {
            all.insert(j);
        }
        return all;
    }

    int getNumVertices() {
        return numVert;
    }

    vector<vector<int>> getAdjList() {
        return adjList;
    }
};

int* BFS(Graph G, int s) {
    int n = G.getNumVertices();
    int* dist = new int[n];
    for (int i = 0; i < n; i++) {
        dist[i] = -1;
    }
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : G.outConnections(v)) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    return dist;
}

#endif