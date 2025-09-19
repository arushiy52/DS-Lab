// Evaluating a postfix expression


# include <iostream>
# include <string>
# include <cstring>
# include <stack>
using namespace std;


inline int Convert_to_int(char digit) {
    return digit-'0';
}


int Perform_Operation(int a, int b, char op) {
    switch (op) {
        case '+' : return a+b;
        case '-' : return a-b;
        case '*' : return a*b;
        case '/' : return a/b;
        case '^' : return pow(a,b);
        default : return 0;
    }
}


int Postfix_Evaluation(string expr) {
    stack <int> s;


    for (int i=0; i<expr.length(); i++) {
        char c = expr[i];
        if (c == ' ') continue;

        // Operand
        if (c>='0' && c<='9' ||
            c>='A' && c<='Z' ||
            c>='a' && c<='z') {
                if (c>='0' && c<='9') {
                    c = Convert_to_int(c);
                }
                s.push(c);
        }

        // Operator
        else {
            // Not having min values to operate on
            if (s.size() < 2) {
                cout << "Invalid Expression " << endl;
                return INT_MIN;
            }

            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            int result = Perform_Operation(val2,val1,c);
            s.push(result);
        }      
    }

    if (s.size() != 1) {
        cout << "Invalid Postfix Expression" << endl;
        return INT_MIN;
    }

    return s.top();

}





int main() 
{
    string expr;
    cout << "Enter Postfix Expression : ";
    getline(cin, expr);

    cout << "Answer : " << Postfix_Evaluation(expr) << endl;
}