#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*top = NULL;

void push(int value){
    Node *t = new Node;
    if(t == NULL){
        cout << "stack overflow" << endl;
    }
    else{
        t->data = value;
        t->next = top;
        top = t;
    }
}


