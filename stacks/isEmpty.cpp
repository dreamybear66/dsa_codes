#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

int isEmpty(Stack st){
    if(st.top == -1)
        return 1;
    else 
        return 0;
}