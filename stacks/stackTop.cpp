#include <iostream>
using namespace std;

struct Stack{
    int top;
    int size;
    int *s;
};

int stackTop(Stack st){
    if(st.top == -1)
        return -1;
    else 
        return st.s[st.top];
}