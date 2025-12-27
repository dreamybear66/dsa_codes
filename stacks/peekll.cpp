#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
}*top = NULL;

int peek(int pos){
    Node *p = top;
    for(int i = 0; i<pos-1 && p!=NULL; i++){
        p= p->next;
    }
    if(p!=NULL){
        return p->data;
    }
    else{
        cout << "invalid position" << endl;
        return -1;
    }
}