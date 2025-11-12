// Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3.

# include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node * next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }
};


class LinkedList {
    public :
    Node * head;
    Node * tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }



    Node * input_list() {
        int data;
        cout << "Enter : " ;
        cin>>data;
        if (data == -1) return NULL;
        head = new Node(data);
        tail = head;
        
        while(data!=-1) {
            cin >> data;
            if (data==-1) continue;
            Node *n = new Node(data);
            tail->next = n;
            tail=n;
        }
        return head;
    }


    void Display() {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }

        Node *temp = head;
        while (temp!=NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int CountDeleteOccurances(Node * &head, int key) {
    int count = 0;
    

    // Deleting key from beg
    while (head!=NULL && head->data == key ) {
        Node * del = head;
        head = head -> next;
        delete del;
        count++;
    }

    Node * temp = head;

    while (temp!=NULL && temp->next!=NULL) {
        // Key data found
        if (temp->next->data == key) {
            Node * del = temp ->next;
            temp->next = del->next;
            delete del;
            count++;
        }
        else {
            temp = temp->next;
        }
    }
    return count;
}




int main()
{
    LinkedList l;
    l.input_list();
    int key,count;
    cout << "Enter key : ";
    cin >> key;
    count = CountDeleteOccurances(l.head, key);
    cout << "Count : " << count<< endl;
    cout << "List after deleting multiple occurrances : " ;
    l.Display();
}
