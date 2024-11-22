#include <iostream>
using namespace std;
template <typename T>

struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    void push(T value) 
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }
    void pop() 
    {
        if (isEmpty()) {
            std::cerr << "Стек порожній нічого видаляти\n";
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    T peek() const 
    {
        if (isEmpty()) {
            throw std::runtime_error("Стек порожній");
        }
        return top->data;
    }
    bool isEmpty() const 
    {
        return top == nullptr;
    }
};
