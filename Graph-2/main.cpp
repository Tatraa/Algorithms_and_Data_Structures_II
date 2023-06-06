#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int numBreaks = 0;

void dfs(int v, vector<int>& listOne, vector<int>& listTwo, int temp) {
    listTwo[v] = temp;
    if (listTwo[listOne[v]] == -1)
        dfs(listOne[v], listOne, listTwo, temp);
    else if (listTwo[listOne[v]] == temp)
        numBreaks++;
}

int main(int argc, char* argv[]) {
    // Aby wyswietlic wyniki najpierw wykonaj ponizsze komendy:
    // g++ -std=c++14 main.cpp -o main
    // ./main tests/test1.txt tests/test2.txt tests/test3.txt tests/test4.txt tests/test5.txt tests/test5.txt tests/test6.txt
    if (argc < 2) {
        cout << "Podaj nazwy plikow jako argumenty wiersza polecen." << endl;
        return 1;
    }

    for (int fileIndex = 1; fileIndex < argc; fileIndex++) {
        ifstream file(argv[fileIndex]);
        if (!file) {
            cout << "Nie mozna otworzyc pliku: " << argv[fileIndex] << endl;
            continue;
        }

        int numSafes = 0;
        file >> numSafes;

        vector<int> graph(numSafes + 1);
        for (int i = 0; i < numSafes; i++) {
            file >> graph[i + 1];
        }

        file.close();

        int numTemp = 0;
        vector<int> graphTemp(numSafes + 1, -1);
        for (int i = 1; i <= numSafes; i++) {
            if (graphTemp[i] == -1) {
                dfs(i, graph, graphTemp, numTemp);
                numTemp++;
            }
        }

        cout << "Minimalnie nalezy zniszczyc w pliku " << argv[fileIndex] << ": " << numBreaks << " sejfy" << endl;

        numBreaks = 0; // Zerowanie zmiennej dla kolejnego pliku
    }

    return 0;
}
