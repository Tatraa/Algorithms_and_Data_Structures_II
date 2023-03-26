#include <iostream>
#include <vector>
#include <algorithm>
#include "priorityque.h"

using namespace std;


int main(){
    PriorityQueue<string> que;

    que.insert("Algo", 2);
    que.insert("Grafy", 1);
    que.insert("!", 3);

    QueueElem<string> maxElem = que.max();
    cout << "Max element: " << maxElem.obj << " (priority " << maxElem.priority << ")" << endl;

    QueueElem<string> extractedElem = que.extractMax();
    cout << "Extracted max element: " << extractedElem.obj << " (priority " << extractedElem.priority << ")" << endl;

    maxElem = que.max();
    cout << "Max element: " << maxElem.obj << " (priority " << maxElem.priority << ")" << endl;

    extractedElem = que.extractMax();
    cout << "Extracted max element: " << extractedElem.obj << " (priority " << extractedElem.priority << ")" << endl;

    maxElem = que.max();
    cout << "Max element: " << maxElem.obj << " (priority " << maxElem.priority << ")" << endl;

    return 0;
}
