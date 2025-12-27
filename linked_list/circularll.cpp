#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n){
    int i;
    Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(i = 1; i<n; i++){
        t = new Node ;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *h){
    do{
        cout << h->data << endl;
        h=h->next;
    }while(h!=Head);
}

int Length(Node *h)
{
    int len = 0;
    do{
        len++;
        h=h->next;
    }while(h!=Head);
    return len;
}

void insert(int x, int index){
    Node *t, *p = Head;
    int i;

    if(index < 0  || index > Length(Head)){
        return;
    }
    if(index ==  0){
        t = new Node;
        t->data = x;
        if(Head == NULL){
            Head = t;
            Head->next = Head;
        }
        else{
            while(p->next != Head){
                p=p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else{
        for(i =0; i<index-1; i++){
            p=p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(Node *p, int index){
    Node *q;
    int i;

    if(index <0 || index > Length(Head)){
        return -1;
    }
    if(index == 0){
        while(p->next != Head){
            p=p->next;
        }
        int x = Head->data;
        if(Head == p){
            delete Head;
            Head = NULL;
        }
        else{
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
        return x;
    }
    else{
        for(i=0; i<index-1; i++){
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        int x = q->data;
        delete q;
        return x;
    }
}


int main(){
    int A[] = {2,3,4,5,6};
    create(A,5);

    Delete(Head,3);
    Display(Head);
    return 0;
}
