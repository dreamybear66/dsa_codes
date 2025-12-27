#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL,*second = NULL, *third = NULL; //global pointer

void create(int A[], int n){ // not clear but i think it will be explained later 
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n){  
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p){
        cout << p->data << endl;
        p=p->next;
    }
}

void RDdisplay(struct Node *p){
    if(p!= NULL){
        RDdisplay(p->next);
        cout << p->data << endl;
    }
}

int count(struct Node *p){
    int count = 0;
    while(p!= NULL){
       count++;
       p=p->next; 
    }
    return count;
}

int RDcount(struct Node *p){
    if(p==NULL){
        return 0;
    }
    else{
        return 1 + RDcount(p->next);
    }
}

int sum(Node *p){
    int sum = 0;
    while(p!=NULL){
        sum += p->data;
        p=p->next;
    }

    return sum;

}

int RDsum(Node *p){
    if(p==0)
        return 0;
    else
        return RDsum(p->next) + p->data;
}

int max(Node *p){
    int max = -32768;
    while(p!=NULL){
        if(p->data > max){
            max = p->data;
        }
        p=p->next;
    }

    return max;
}

int RDmax(Node *p){
    int max = -32768;
    if(p==0){
        return max; // #include <climits> me INT_MIN use kar sakte hai
    }
    
    int x= RDmax(p->next);
    return x>p->data ? x:p->data;
    
}

Node* search(Node *p, int key ){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

Node* RDsearch(Node *p, int key){
    if(p==NULL)
        return NULL;
    else
        return p;
    
    return RDsearch(p->next, key);
    
}

Node* improveSearch(Node *p, int key){
    Node *q = NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

Node* insert(int index, int x){
    Node *t;
    if(index <0 || index>count(first)){
        return NULL;
    }
    t = new Node;
    t->data = x;  
    
    if(index ==0){
        t->next = first;
        first = t;
    }
    else{
    Node *p = first;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    t->next = p->next;
    p->next =t;
    }   
    
    return first;
}

//Node *last = NULL;
/*void InsertLast(int x){
    Node *t = new Node;
    t->data  =x;
    t->next = NULL;
    if(first == NULL){
        first =  last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}
*/

Node* sortedInsert(Node* p,int x){
    Node  *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(first == NULL){
        first = t;
    }
    else{
        while(p!=NULL && p->data <x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }

    return first;
}

int Delete(int pos){
    Node *p = first;
    Node *q = NULL;
    int x = -1, i;
    if(pos == 1)
    {
        x = first->data;
        p = first;
        first = first->next;
        delete p;
    }
    else
    {
        for(i = 0;i<pos-1 && p;i++){
            q = p;
            p = p->next;
        }
        if(p!=NULL){
            q->next = p->next;
            x= p->data;
            delete p;
        }
    }

    return x;
}

int checkSorted(Node *p){
    int x = -32768;
    while(p!=NULL){
        if(p->data < x){
            return false; // false = 0
        }
        x= p->data;
        p=p->next;
    }

    return true; // true = 1
}

Node* removeDuplicate(Node *p){
    Node *q = first->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q=p->next;
        }
    }

    return first;
}

void reverse(Node *p){
    Node *q = NULL;
    Node *r = NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}

void RDreverse(Node *q, Node *p){
    if(p!=NULL){
        RDreverse(p,p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

Node* concat(Node *p, Node *q){
    if(p==NULL) return q;
    if(q==NULL) return p;
    
    third = p;
    while(p->next !=NULL){
        p=p->next;
    }
    p->next = q;

    return third;   
}

void merge(Node *p, Node *q){
    Node *last;
    if(p->data <q->data){
        third =  last = p;
        p=p->next;  
        third->next = NULL;
    }
    else{
        third =  last = q;
        q=q->next;  
        third->next = NULL;
    }

    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p=p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q=q->next;
            last->next = NULL;
        }
    }
    if(p!=NULL){
        last->next = p;
    }
    if(q!=NULL){
        last->next = q;
    }
}

int isloop(Node *f){
    Node *p, *q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);

    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    int A[] = {10,20,30,40,50};
    int B[] = {5,15,25,35,45};
    create(A,5);
    create2(B,5);
    merge(first, second);
    display(third);
    
    return 0;
}





