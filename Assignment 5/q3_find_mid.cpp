//Write a program to find the middle of a linked list.
// Using Tortiose and hare 

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




Node * FindMiddle(Node * head) {
    if (head==NULL) {
        cout << "Empty List" << endl;
        return NULL;
    }
    Node * skip1 = head;
    Node * skip2 = head;

    while (skip2!=NULL && skip2->next!=NULL) {
        skip1 = skip1->next;
        skip2 = skip2->next->next;
    }
    cout << "Middle element of list : " << skip1->data << endl;
    return head;
}




int main()
{
    LinkedList l;
    l.input_list();
    l.head = FindMiddle(l.head);

}