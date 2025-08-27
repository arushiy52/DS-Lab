// Checking whether parenthesis are balanced or not


# include <iostream>
# include <string>
# include <climits>
using namespace std;

class Stack {
    char *data;
    int capacity;
    int nextIndex;

    public:

    Stack() {
        data = new char[4];
        capacity = 4;
        nextIndex = 0;
    }

    bool isEmpty() {
        if(nextIndex == 0) return true;
        else return false;
    }


    void push(char c) {
        if (nextIndex == capacity) {
            char *newdata = new char[2*capacity];
            for (int i=0; i<nextIndex; i++) {
                newdata[i] = data[i];
            }
            capacity = 2*capacity;
            delete [] data;             
            data = newdata;
        }
        data[nextIndex] = c;
        nextIndex++;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return CHAR_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

};


bool BalancedParenthesis(string str) {

    Stack s;

    for (int i=0; i<str.length(); i++) {

        char hmm = str[i];

        if (str[i]=='(' || str[i]=='{' || str[i]=='[') {
            s.push(hmm);
        }
        if (str[i]==')' || str[i]=='}' || str[i]==']') {
            if (s.isEmpty()) return false;

            char top = s.pop();
            if (str[i] == ')' && top != '(' ||
                str[i] == ']' && top != '[' ||
                str[i] == '}' && top != '{') 
                return false;
            }
    }
    return s.isEmpty();
}


int main() 
{
    string str;
    cout << "Enter string : ";
    cin >> str;
    if (BalancedParenthesis(str))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    cout << endl;
}