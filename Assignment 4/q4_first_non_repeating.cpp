// Write a program to find first non-repeating character in a string using Queue.
// Sample I/P: a a b c Sample O/P: a -1 b b


# include <iostream>
# include <queue>
# include <string>
using namespace std;


char FirstNonRepeating(string str) {
    queue<char> sq;
    char count[256] = {0};

    for (int i=0; i<str.length(); i++) {
        if (str[i] == ' ') continue;

        count[str[i]]++;
        sq.push(str[i]);
    }

    // Now the array stores count of each char in the string
    // An occurance of no more than 1 means count of that char must be 1
    // So we pop those characters from queue until we get a count of 1
    while (!sq.empty() && count[sq.front()]!=1) {
        sq.pop();
    }

    if (sq.empty()) return '\0';
    else return sq.front();
}




int main()
{
    string str;
    cout << "Enter String : ";
    getline(cin, str);

    char x = FirstNonRepeating(str);
    cout << "First Non-Repeating char : " << x << endl;
}