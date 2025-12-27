#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Stack{
    private:
        Node* top;
    public:
        Stack(){top = NULL;}
        void push(int value);
        int pop();
        void display();
};

void Stack::push(int value){
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

int Stack::pop(){
    int x = -1;
    if(top == NULL){
        cout << "stack is empty" << endl;
    }
    else{
        Node *t = top;
        x = t->data;
        top = top->next;
        delete t;
        cout << "popped value is: " << x << endl;
    }
    
    return x;
}

void Stack::display(){
    Node *p = top;
    while(p){
        cout << p->data << endl;
        p = p->next;
    }
}

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Stack elements are: " << endl;
    st.display();

    st.pop();
    st.pop();

    cout << "Stack elements after popping two values: " << endl;
    st.display();

    return 0;
}