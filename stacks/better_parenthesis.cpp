#include <iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
};

class Stack{
    private:
        Node* top;
    public:
        Stack(){top = NULL;}
        void push(char value);
        char pop();
        void display();
        int isBalanced(char *exp);
};

void Stack::push(char value){
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

char Stack::pop(){
    char x = -1;
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

int Stack::isBalanced(char *exp){
    int i;
    for(i=0; exp[i] != '\0';i++){
        if(exp[i] =='(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(top == NULL)
                return 0;

            char x = top->data;

            if(abs(exp[i] - x) == 1 || abs(exp[i] - x) == 2){
                pop();
            }
            else{
                return 0;
            }
        }
    }

    return top == NULL ? 1:0;
}

int main(){
    char exp[] = "{([a+b]*[c-d])}";
    Stack st;
    cout << st.isBalanced(exp) << endl;

    return 0;
}