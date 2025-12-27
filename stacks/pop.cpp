#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

void push(Stack *st, int value){

    if(st->top == st->size - 1){
        cout << "stack overflow" << endl;
    }
    else{
        st->top++;
        st->s[st->top] = value;
    }
}

int pop(Stack *st){
    int x = -1;
    if(st->top == -1){
        cout << "stack is empty" << endl;
    }
    else{
        x = st->s[st->top];
        st->top--;
    }

    return x;
}

int main() {
    Stack st;
    st.size = 5;
    st.top =  -1;
    st.s = new int[st.size];
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);

    int popped_value = pop(&st);
    cout << "popped value is: " << popped_value << endl;

    return 0;
}