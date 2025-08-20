// To delete all vowels from a string

# include <iostream>
using namespace std;

void shift(char str[], int k) {
    for (int i = k; str[i] != '\0'; i++){
        str[i] = str[i+1];
    }
}


void delete_vowels(char str[]) {

    char vowel[] = "aeiou";
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j=0 ; j<=5 ; j++) {
            if (str[i] == vowel[j]) {
                shift(str,i);
            }
        }
    }
}


int main()
{
    char *str = new char[100];
    cout << "Enter string : " ;
    cin >> str;
    delete_vowels(str);
    cout << str << endl;
}