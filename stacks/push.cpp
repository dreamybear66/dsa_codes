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

int main() {
    Stack st;
    st.size = 5;
    st.top =  -1;
    st.s = new int[st.size];
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);

    for(int i = 0; i <= st.top; i++){ //for now i have used for loop, maybe aage display function banaunga
        cout << st.s[i] << endl;
    }

    return 0;
}