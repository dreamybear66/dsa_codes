#include <iostream>
using namespace std;

int main() {
    char str[] = "welcome";
    int i;
    for(i=0;str[i]!= '\0';i++){
        str[i] -= 32;
    }
    cout << "uppercase string: " << str << endl;

    return 0;
}