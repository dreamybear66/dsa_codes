#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

int peek(Stack st, int pos){
    int x = -1;
    if(st.top-pos+1 < 0){
        cout << "invalid position" << endl;
    }
    else{
        x = st.s[st.top-pos+1];
    }

    return x;
}
