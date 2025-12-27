#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*top = NULL;

int isEmpty(){
    if(top == NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    Node *t = new Node;
    if(t == NULL)
        return 1;
    else{
        delete t;
        return 0;
    }
}

int stackTop(){
    if(top == NULL)
        return -1;
    else
        return top->data;
}