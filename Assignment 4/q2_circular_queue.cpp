// Develop a menu driven program demonstrating the following operations on Circular Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().



# include <iostream>
using namespace std;
template <typename T>

class QueueUsingArray {
    T *data;
    int size;
    int capacity;
    int firstIndex;
    int nextIndex;

    public:
    QueueUsingArray(int len) {
        data = new T[len];
        this -> size = 0;
        capacity = len;
        firstIndex = -1;
        nextIndex = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
        // Returns true if expression is true, otherwise false
        // 0==0 -> true, 4==0 -> false
    }

    bool isFull() {
        return size==capacity;
    }

    // Insert element 
    void enqueue(T element) {
        // Inserting first element
        if (firstIndex == -1) firstIndex = 0;

        // If queue is full
        if (size == capacity) {
            cout << " Queue is full" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex+1) % capacity;
        size++;
    }

    T front() {
        if (isEmpty()) {
            cout << " Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue() {
        if (isEmpty()) {
            cout << " Queue is empty " << endl;
            return 0;
        }

        T del = data[firstIndex];
        firstIndex = (firstIndex+1) % capacity;
        size-- ;
        // If i delete last element, reset queue (recommended)
        if (size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return del;
    }


    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        int idx = firstIndex;
        for (int i = 0; i < size; i++) {
            cout << data[idx] << " ";
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }

};




int main() {
    int capacity;
    cout << "Enter capacity of queue : ";
    cin >> capacity;
    
    QueueUsingArray<int> q(capacity);
    
    int choice, element;
    
    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Display" << endl;
        cout << "7. Get Size" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                q.enqueue(element);
                break;
                
            case 2:
                element = q.dequeue();
                if (element != 0 || !q.isEmpty()) {
                    cout << "Dequeued element: " << element << endl;
                }
                break;
                
            case 3:
                element = q.front();
                if (element != 0 || !q.isEmpty()) {
                    cout << "Front element: " << element << endl;
                }
                break;
                
            case 4:
                if (q.isEmpty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << "Not empty" << endl;
                }
                break;
                
            case 5:
                if (q.isFull()) {
                    cout << "Full" << endl;
                } else {
                    cout << "Not full" << endl;
                }
                break;
                
            case 6:
                q.display();
                break;
                
            case 7:
                cout << "Size = " << q.getSize() << endl;
                break;
                
            case 0:
                cout << "Exiting program" << endl;
                break;
                
            default:
                cout << "Invalid choice." << endl;
        }
        
    } while(choice != 0);
    
    return 0;
}
