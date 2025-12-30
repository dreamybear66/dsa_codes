#include <iostream>
#include <cstring>
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
        char *infix_to_postfix(char *infix);
        int isOperand(char x);
        int precedence(char x);
};

void Stack::push(char value ){
    Node *t = new Node;
    if(t == NULL){
        cout << "stack is full" << endl;
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
        cout << "stack is empty"  << endl;
    }
    else{
        Node *t = top;
        x  = t->data;
        top = top->next;
        delete t;
    }

    return x;
}

int Stack::precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    return 0;
}

int Stack::isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    else{
        return 1;
    }
}

char *Stack::infix_to_postfix(char *infix){
    char *postfix;
    int len =strlen(infix);
    postfix =  new char[len+2]; //+2 for '\0' and sentinel
    int i=0,j=0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(precedence(infix[i]) > precedence(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(top != NULL){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}


int main(){
    char *infix = (char*)"a+b*c*d/e/f-g+h";
    Stack st;
    st.push('#');  //if the stack is empty push a sentinel value(so that no error occur bcoz of if(precedence(infix[i]) > precedence(top->data)) condition)
    char *postfix = st.infix_to_postfix(infix);
    cout << "postfix exp : " << postfix << endl;

    return 0;
}