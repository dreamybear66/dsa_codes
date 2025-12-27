#include <iostream>
using namespace std;

struct Stack{
    int top;
    int size;
    int *s;
};

int isFull(Stack st){
    if(st.top == st.size -1)
        return 1;
    else
        return 0;
}