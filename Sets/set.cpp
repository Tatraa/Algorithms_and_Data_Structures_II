#include <iostream>

template <typename T>
class Set : public std::error_code {
private:
    T *array;
    int capacity;
    int count;

    void resize(int newCapacity) {
        int *newArray = new int[newCapacity];
        for (int i = 0; i < count; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public:
    Set() {
        capacity = 10;
        array = new T[capacity];
        count = 0;
    }

    ~Set() {
        delete[] array;
    }

    void insert(T x) {
        if (isMember(x)) {
            return;
        }

        if (count == capacity) {
            resize(capacity * 2);
        }

        int i = count - 1;
        while (i >= 0 && array[i] > x) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = x;
        count++;
    }

    bool isMember(T x) {
        int left = 0;
        int right = count - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == x) {
                return true;
            } else if (array[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    void remove(T x) {
        int left = 0;
        int right = count - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == x) {
                for (int i = mid; i < count - 1; i++) {
                    array[i] = array[i + 1];
                }
                count--;

                if (count < capacity / 4) {
                    resize(capacity / 2);
                }

                return;
            } else if (array[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    T pop() {
        if (count == 0) {
            throw std::out_of_range("Set is empty");
        }

        int x = array[0];
        remove(x);
        return x;
    }

    int size() {
        return count;
    }

    Set intersection(const Set &S2) {
        Set result;
        int i = 0;
        int j = 0;
        while (i < count && j < S2.count) {
            if (array[i] < S2.array[j]) {
                i++;
            } else if (array[i] > S2.array[j]) {
                j++;
            } else {
                result.insert(array[i]);
                i++;
                j++;
            }
        }
        return result;
    }

    Set difference(const Set &S2) {
        Set result;
        int i = 0;
        int j = 0;
        while (i < count && j < S2.count) {
            if (array[i] < S2.array[j]) {
                result.insert(array[i]);
                i++;
            } else if (array[i] > S2.array[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        while (i < count) {
            result.insert(array[i]);
            i++;
        }
        return result;
    }

    Set _union(const Set &S2) {
        Set result;
        int i = 0;
        int j = 0;
        while (i < count && j < S2.count) {
            if (array[i] < S2.array[j]) {
                result.insert(array[i]);
                i++;
            } else if (array[i] > S2.array[j]) {
                result.insert(S2.array[j]);
                j++;
            } else {
                result.insert(array[i]);
                i++;
                j++;
            }
        }
        while (i < count) {
            result.insert(array[i]);
            i++;
        }
        while (j < S2.count) {
            result.insert(S2.array[j]);
            j++;
        }
        return result;
    }

    //funkcja pomocnicza
    void display() const {
        std::cout << "{ ";
        for (int i = 0; i < count; i++) {
            std::cout << array[i];
            if (i != count - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " }" << std::endl;
    }

};