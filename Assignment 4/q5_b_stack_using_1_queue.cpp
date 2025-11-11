// Write a program to implement a stack using  (b) One Queue.


# include <iostream>
# include <queue>
using namespace std;


class StackUsingTwoQueues {
    public:
    queue<int> q;


    int size() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }
    

    int top() {
        if (empty()) {
            cout << "Stack is empty" << endl;
        }
        return q.front();
    }

    void push(int data) {
        // We want newest element to be in front of q1 to be able to follow LIFO
        // Save current size before pushing.. for no. of times shifting is req
        int n = q.size();
        q.push(data);
        // Rotating the queue
        for (int i=0; i<n; i++) {
            q.push(q.front());
            q.pop();
        }

    }


    void pop() {
        if (empty()) {
            cout << "Empty stack" << endl;
        }
        q.pop();
    }
};




int main() 
{
    StackUsingTwoQueues s;
    int choice;

    while (true) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Check if Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if (val != -1)
                    cout << "Top element: " << s.top()<< endl;
                break;
            case 4:
                cout << "Size: " << s.size() << endl;
                break;
            case 5:
                if (s.empty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
