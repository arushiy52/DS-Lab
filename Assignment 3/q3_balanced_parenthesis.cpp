// To check if parenthesis are balanced or not in an expression having oparands, parenthesis and characters

# include <iostream>
# include <stack>
# include <string>
using namespace std;


bool balanced_paranthesis(string expr) {
    stack <char> s;
    int top;

    for (int i=0; i<expr.length(); i++) {

        char yoo = expr[i];

        if (yoo =='(' || yoo =='[' || yoo =='{') {
            s.push(yoo);
            top = s.top();
        }
        
        if (yoo ==')' || yoo ==']' || yoo =='}') {
            // If a bracket is closed without being opened, NB
            if (s.empty()) return false;
            
            if (yoo == ')' && top == '(' ||
                yoo == ']' && top == '[' ||
                yoo == '}' && top == '{')
                // If string element matches the top of stack, remove
                s.pop(); 
        }
        else continue;
        
    }
    // If an opening bracket is still remaining in stack, parenthesis are not balanced.. return false
    return s.empty();       
}


int main()
{
    string expr;
    cout << "Enter expresion : ";
    cin >> expr;

    if (balanced_paranthesis(expr) == true) {
        cout << "Balanced " << endl;
    }
    else cout << "Not Balanced" << endl;
}
