#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first = NULL;

void create(int A[],int n){
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void middle(Node *first){
    Node *p,*q;
    p= first;
    q = first;
    while(q!=NULL){
        q = q->next;
        if(q!=NULL) q = q->next;
        if(q!=NULL) p = p->next;
    }
    cout << "Middle element is: " << p->data << endl;
}

int main(){
    int A[] = {10,20,30,40,50,60,70};
    create(A,7);
    middle(first);
    return 0;
}