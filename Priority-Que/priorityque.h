#ifndef PRIORITYQUE_H
#define PRIORITYQUE_H

#include <vector>

template<typename T>
struct QueueElem {
    int priority;
    T obj;
};

template<typename T>
class PriorityQueue {
public:
    PriorityQueue() : size(0) {}

    void insert(T obj, int priority) {
        elems.push_back({priority, obj});
        size++;
        heapifyUp(size - 1);
    }

    QueueElem<T> max() const {
        if (size == 0) throw std::out_of_range("Priority queue is empty");
        return elems[0];
    }

    QueueElem<T> extractMax() const {
        if (size == 0) throw std::out_of_range("Priority queue is empty");
        QueueElem<T> maxElem = elems[0];
        elems[0] = elems[size - 1];
        elems.pop_back();
        size--;
        heapifyDown(0);
        return maxElem;
    }

private:
    std::vector<QueueElem<T>> elems;
    int size;

    void heapifyUp(int index) {
        while (index > 0 && elems[(index - 1) / 2].priority < elems[index].priority) {
            std::swap(elems[index], elems[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int maxIndex = index;
        int leftChildIndex = 2 * index + 1;
        if (leftChildIndex < size && elems[leftChildIndex].priority > elems[maxIndex].priority) {
            maxIndex = leftChildIndex;
        }
        int rightChildIndex = 2 * index + 2;
        if (rightChildIndex < size && elems[rightChildIndex].priority > elems[maxIndex].priority) {
            maxIndex = rightChildIndex;
        }
        if (index != maxIndex) {
            std::swap(elems[index], elems[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
};

#endif