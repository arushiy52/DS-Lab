// Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

# include <iostream>
# include <queue>
using namespace std;



void DisplayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}



void InterweaveQueue(queue<int> &q) {
    if (q.size() <= 1) return;

    int half = q.size()/2;
    // Separating half of the queue
    queue<int> temp;
    for (int i=0; i<half; i++) {
        temp.push(q.front());
        q.pop();
    }

    while (temp.size() != 0) {
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }

    
}



int main()
{
    queue<int> q;
    int data;
    cout << "Enter Queue (-1 to stop ) : ";
    cin >> data;
    while (data!=-1) {
        q.push(data);
        cin >> data;
    }
    DisplayQueue(q);
    cout << "After Interweaving : ";
    InterweaveQueue(q);
    DisplayQueue(q);
    

}