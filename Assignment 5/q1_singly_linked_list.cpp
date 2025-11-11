// Develop a menu driven program for the following operations on a Singly Linked list


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



    Node * Insert() {
        int data,pos;
        cout << "Enter data : ";
        cin >> data;
        cout << "Enter position index : ";
        cin >> pos;

        Node * n = new Node(data);
        Node *ins = head;   // Pointer to track insertion point

        // Insertion at index 0
        if (pos == 0) {
            n->next = head;
            head = n;
            return head;
        }

        for (int i=0; i<pos-1 && ins!=NULL; i++) {
            ins = ins->next;
        }
        if (ins!=NULL) {
        n -> next = ins->next;
        ins -> next = n;           
        }

        return head;
        
    }


    void InsertAtBeginning(int data) {
        Node * n = new Node(data);
        n->next = head;
        head = n;
        
    }


    void InsertAtEnd(int data) {
        Node * n = new Node(data);

        if (head==NULL) {
            head = n;
        }

        // tail->next = n;
        else {
           Node * temp = head;
           while (temp->next!=NULL) {
            temp = temp->next;
           }
           temp -> next = n; 
           temp = temp->next;
        }


    }


    Node * Delete() {
        int pos;
        cout << "Enter Position to delete : ";
        cin >> pos;
        Node * del = NULL;

        if (pos==0){
            del = head;
            head = head->next;
            delete del;
            return head;
        }

        Node * trav = head;
        for (int i=0; i<pos-1; i++) {
            trav = trav->next;
        }

        del = trav->next;
        trav -> next = del -> next;
        delete del;
        
        return head;
    }


    void DeleteFromBeginning() {
        Node * del = head;
        head = head->next;
        delete del;
    }


    void DeleteAtEnd() {
        Node * del = NULL;
        Node * temp = head;

        if (head == NULL) {
            cout << "Empty List" << endl;
        }

        else if (head -> next == NULL) {
            del = head;
            head = NULL;
            delete del;
        }

        else {
        while (temp -> next -> next != NULL)    // Takes us to second last element 
        {
            temp = temp -> next;
        }
        del = temp -> next;
        tail = temp;
        tail -> next = NULL;
        delete del;
        }
    }




    int Search(int val) {
        if (head==NULL) {
            cout << "Empty List" << endl;
            return -1;
        }
        int pos = 0;
        Node * temp = head;
        
        while (temp!=NULL) {
            if (temp->data == val) return pos;
            temp = temp->next;
            pos++;
        }
        cout << "Value not Found" << endl;
        return -1;
    }




    void DeleteData(int val) {
        if (head==NULL) {
            cout << "Empty List" << endl;
        }
        Node * del = NULL;
        if (head->data==val) {
            DeleteFromBeginning();
        }

        int pos = Search(val);
        Node * trav = head;
        for (int i=0; i<pos-1; i++) {
            trav = trav->next;
        }
        del = trav->next;
        trav->next = trav->next->next;
        delete del;

    }


    
};





int main() {
    LinkedList l;
    int choice, val;

    while (true) {
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Beginning" << endl;
        cout << "4. Delete from End" << endl;
        cout << "5. Delete by Value" << endl;
        cout << "6. Search" << endl;
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                l.InsertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                l.InsertAtEnd(val);
                break;
            case 3:
                l.DeleteFromBeginning();
                break;
            case 4:
                l.DeleteAtEnd();
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                l.DeleteData(val);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                cout << "Position: " << l.Search(val) << endl;
                break;
            case 7:
                l.Display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
