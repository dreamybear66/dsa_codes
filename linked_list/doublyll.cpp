#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
}*first = NULL;

void create(int A[], int n){
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node *p){
    while(p!=NULL){
        cout << p->data << endl;
        p=p->next;
    }
}

int Length(Node *p){
    int len =0;
    while(p!=NULL){
        len++;
        p=p->next;
    }

    return len;
}

void Insert(Node *p, int index, int x){
    Node *t;
    if(index<0 || index > Length(p)){
        return;
    }

    if(index == 0){
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;;
        if(first != NULL){
            first->prev = t;
        }
        first = t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t =new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next != NULL){
            p->next->prev = t;
        }
        p->next = t;
    }
}

void Delete(Node *p, int index){
    Node *q = NULL;
    if(index < 0 || index > Length(p)){
        return;
    }

    if(index == 0){
        q = first;
        first = first->next;
        if(first != NULL){
            first->prev = NULL;
        }
        int x = q->data;
        delete q;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next = p->next;
        if(p->next != NULL){
            p->next->prev = p->prev;
        }
        int x = p->data;
        delete p;
    }
}

void reverse(Node *p){
    Node *temp;

    while(p != NULL){
        // swap next and prev
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        // when p->prev is NULL, p is the new head
        if(p->prev == NULL){
            first = p;
        }

        // move p to original next (which is now in prev)
        p = p->prev;
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    create(A,5);
    reverse(first);
    

    Display(first);
    
    return 0;
}