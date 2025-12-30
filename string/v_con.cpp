#include <iostream>
using namespace std;

int main(){
    char str[] = "welcome to data structures";
    int i, v_count = 0, c_count = 0;
    for(i=0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
           str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            v_count++;
        }
        else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            c_count++;
        }
    }

    cout << "Number of vowels: " << v_count << endl;
    cout << "Number of consonants: " << c_count << endl;

    return 0;
}