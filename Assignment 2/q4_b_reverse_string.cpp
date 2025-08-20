// Reverse a string

# include <iostream>
# include <cstring>
using namespace std;

void reverse_string(char *);

int main()
{
    char *str = new char[100];
    cout << "Enter string : ";
    cin >> str;
    reverse_string(str);
    cout << str << endl;
}

void reverse_string(char *str) {

    for (int i = 0, j = strlen(str)-1 ; i<j; i++,j--) {
        
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        
    }
}