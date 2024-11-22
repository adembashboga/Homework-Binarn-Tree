#include <iostream>
using namespace std;
template <typename T>

class Queue {
private:
    Node<T>* front;
    Node<T>* rear; 

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Черга порожня нічого видаляти\n";
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) { 
            rear = nullptr;
        }
        delete temp;
    }
    T peek() const {
        if (isEmpty()) {
            throw std::("Черга порожня");
        }
        return front->data;
    }
    bool isEmpty() const {
        return front == nullptr;
    }
};
