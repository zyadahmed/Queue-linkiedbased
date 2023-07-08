//
// Created by ziad on 7/8/23.
//

#ifndef QUEUE_LINKIEDBASED_QUEUE_H
#define QUEUE_LINKIEDBASED_QUEUE_H
#include <stdexcept>
using namespace std;
template <class T>
        struct Node{
            T data;
            Node<T> *next;
        };
template <class T>
class Queue {
private :
    Node<T> * front;
    Node<T> *rear;
public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    Queue(const Queue &queue){
        front = nullptr;
        rear = nullptr;
        Node<T> * current = queue.front;
        while(current != nullptr){
            enQueue(current->data);
            current = current->next;
        }
    }
    void copy(Queue<T> &otherQueue) const{
        if(this->front== otherQueue.front){
            throw invalid_argument("Self assigment");
        }
        Node<T> * current =  front;
        while(current!= nullptr){
            enQueue(current->data);
            current = current->next;
        }
    }

    bool isEmpty() const {
        return (front == nullptr);
    }
    void enQueue(T data){
        Node<T> * newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        if(front==nullptr){
            front = newNode;
            rear = newNode;

        }else{
            rear->next =  newNode;
            rear = newNode;
        }

    }
    void deQueue(){
        if(front== nullptr){
            throw out_of_range("Queue is Empty");
        }
        Node<T> * temp = front;
        if(front==rear){
            front = nullptr;
            rear = nullptr;
            delete temp;
        }else{
            front = front->next;
            delete temp;
        }
    }
    T top(){
        if(front== nullptr){
            throw out_of_range("Queue is Empty");
        }
        return front->data;
    }
};


#endif //QUEUE_LINKIEDBASED_QUEUE_H
