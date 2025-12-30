#include <iostream>
using namespace std;

int main(){
    char str[] = "welcome to  data structures";
    int i, word_count = 1;
    for(i=0; str[i] != '\0'; i++){
        if(str[i] == ' ' && str[i-1] != ' '){
            word_count++;
        }
    }
    cout << "Number of words: " << word_count << endl;
    return 0;
}