// C++ Program to remove the vowels from a string
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int j = 0;

    string str = "GeeksforGeeks";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i'
            && str[i] != 'o' && str[i] != 'u'
            && str[i] != 'A' && str[i] != 'E'
            && str[i] != 'I' && str[i] != 'O'
            && str[i] != 'U') {
                cout<< "J : "<<j<<endl;
            str[j++] = str[i];

        }
    }
    while (j < str.size()) {

        str[j] = '\0';

        j++;
    }
    cout << "String without vowels: " << str << endl;

    return 0;
}