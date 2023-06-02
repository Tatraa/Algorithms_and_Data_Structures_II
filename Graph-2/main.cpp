#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    int getNumVertices() {
        return numVertices;
    }

    vector<int> findMinSejfs() {
        vector<int> result;
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        vector<int> brokenSejfs(numVertices, 0);
        queue<int> queue;

        visited[0] = true;
        queue.push(0);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            for (int neighbor = 0; neighbor < numVertices; neighbor++) {
                if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;

                    brokenSejfs[neighbor] = brokenSejfs[current] + 1;

                    queue.push(neighbor);
                }
            }
        }

        for (int i = 0; i < numVertices; i++) {
            if (brokenSejfs[i] == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    int n; // Liczba sejfów
    cin >> n;

    Graph graph(n);

    // Wczytujemy informacje o sejfach
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;

        if (key != 0) {
            graph.addEdge(i, key - 1);
        }
    }

    vector<int> result = graph.findMinSejfs();

    cout << "Liczba sejfow do zniszczenia: " << result.size() << endl;
    cout << "Numery sejfow do zniszczenia: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}