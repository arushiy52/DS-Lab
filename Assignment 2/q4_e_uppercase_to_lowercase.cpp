// Convert character from uppercase to lowercase

# include <iostream>
# include <string>
using namespace std;


void upper_to_lower(string s, int len) {
    for (int i = 0; i<s.length(); i++) {
        if (int(s[i]) < 90) {
            s[i] = s[i] + 32;
        }
        else continue;
    }
    cout << s;
}



int main()
{
    string str;
    cout << "Enter string : ";
    getline(cin , str);
    int len = str.length();
    upper_to_lower(str, len);

}
