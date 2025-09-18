// // Infix to Posfix Conversion

// # include <iostream>
// # include <string>
// # include <stack>
// using namespace std;


// int priority(char c) {
//     if (c=='^') return 3;
//     else if (c=='*' || c=='/') return 2;
//     else if(c=='+' || c=='-') return 1;
//     else return 0;
// }


// string infix_to_postfix(string expr) {

//     stack <char> s;
//     string post;

//     for (int i = 0; i<expr.length(); i++) {
//         if (expr[i]>='A' && expr[i]<='Z'||
//             expr[i]>='a' && expr[i]<='z'||
//             expr[i]>='0' && expr[i]<='9') {
//             post = post + expr[i];
//         }

//         else if (expr[i] == '(') {
//         s.push('(');
//         }

//         else if (expr[i] == ')') {
//             while (!s.empty() && s.top()!='(') {
//                 post = post +s.top();
//                 s.pop();
//             }
//             s.pop();        // Remove Opening Bracket
//         }

//         // Operator
//         else {
//             while (!s.empty() && priority(s.top()) >= priority(expr[i]) ) {
//                 post = post + s.top();
//                 s.pop();
//             }
//             s.push(expr[i]);
//         }
//     }
    
//     while(!s.empty()) {
//         post = post + s.top();
//         s.pop();
//     }
//     return post;
// }








# include <iostream>
# include <string>
# include <stack>
using namespace std;


int priority(char c) {
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    else return 0;
}


string infix_to_postfix(string expr) {
    stack <char> s;
    string post;

    for (int i=0; i<expr.length(); i++) {
        char c = expr[i];

        if (c >= 'A' && c <='Z' ||
            c >= 'a' && c <='z' ||
            c >= '0' && c <='9') {
                post = post + c;
            }

        else if (c == '(') {
            s.push('(');
        }

        else if (c == ')') {
            while (!s.empty() || s.top() == '(') {
                post = post + s.top();
                s.pop();
            }
            s.pop();
        }

        else {
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                post = post + s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        post = post + s.top();
        s.pop();
    }
    return post;
}


int main()
{
    string expr;
    cout << "Enter string : ";
    getline(cin, expr);
    cout << infix_to_postfix(expr) << endl;
}