#include <iostream>
using namespace std;

int main(){
    char str[] ="anip$123";
    int i;
    for(i= 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9'){
            continue;
        } 
        else{
            cout << "String is not valid." << endl;
        }
    }

    return 0;
}