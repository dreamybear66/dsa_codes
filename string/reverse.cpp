#include <iostream>
using namespace std;

int main(){
    char str[] = "welcome";
    char strB[7],temp;
    int i,j;

    for(j=0;str[j]!= '\0';j++){

    }
    for(i=0;i<j;i++,j--){
        temp = str[i];
        str[i] = str[j-1];
        str[j-1] = temp;
    }

    cout << "Reversed string: " << str << endl;

    return 0;
}