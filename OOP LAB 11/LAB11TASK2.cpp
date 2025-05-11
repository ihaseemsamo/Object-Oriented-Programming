#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "QueueOverflowException - what(): std::exception";
    }
};

class QueueUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "QueueUnderflowException - what(): std::exception";
    }
};

template <typename T>
class Queue {
    int size;
    int front, rear;
    T* data;
public:
    Queue(int s) : size(s), front(0), rear(0) {
        data = new T[size];
    }

    void enqueue(T val) {
        if (rear == size)
            throw QueueOverflowException();
        data[rear++] = val;
    }

    T dequeue() {
        if (front == rear)
            throw QueueUnderflowException();
        return data[front++];
    }

    ~Queue() {
        delete[] data;
    }
};

int main() {
    Queue<int> q(2);
    try {
        q.enqueue(10);
        q.enqueue(20);
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(30); // Will throw
    } catch (const QueueOverflowException& e) {
        cout << "Caught " << e.what() << endl;
    }

    try {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue();
        q.dequeue();
        q.dequeue(); // Will throw
    } catch (const QueueUnderflowException& e) {
        cout << "Caught " << e.what() << endl;
    }

    return 0;
}
