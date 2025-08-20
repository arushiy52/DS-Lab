// Conacatenate two strings

# include <iostream>
using namespace std;


void concatenate(char s1[], char s2[]);

int main()
{
    char *s1 = new char[100];
    char *s2 = new char[100];
    cout << "Enter first string : ";
    cin >> s1;
    cout << "Enter second string : ";
    cin >> s2;
    

    concatenate(s1,s2);
    cout << s1;
}



void concatenate(char s1[], char s2[]) {

    int len = 0;
    for (int i = 0 ; s1[i] != '\0'; i++) {
        len = len+1;
    }
    
    for (int i = len, j=0; s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }
}
