#include <bits/stdc++.h>
using namespace std;
class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int val)
        {
            data = val;
            next = nullptr;
        }
    };

    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Traversal...

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << "\n";
    }

    // Insert at the Beginning...

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the End...

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at a Position...

    void insertAtPosition(int pos, int val)
    {
        if (pos == 0)
        {
            insertAtHead(val);
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Invalid Position..\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete head...

    void deleteHead()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp = head;
        head = temp->next;

        delete temp;
    }

    // Delete tail...

    void deleteTail()
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;

        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at a Position...

    void deleteAtPosition(int pos)
    {
        if (head == nullptr)
        {
            return;
        }
        if (pos == 0)
        {
            deleteHead();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr && temp->next == nullptr)
        {
            cout << "Invalid Position..\n";
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;

        delete nodeToDelete;
    }

    // Search in the Linked List...

    bool search(int key)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Reverse a Linked List...

    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    // Length...
    int length()
    {

        int count = 0;

        Node *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main()
{
    LinkedList list;
    list.insertAtHead(20);
    list.insertAtHead(10);

    cout << "Linked List: ";
    list.display();

    list.insertAtTail(30);
    list.insertAtTail(50);

    cout << "Linked List: ";
    list.display();

    list.insertAtPosition(3, 40);

    cout << "Linked List: ";
    list.display();

    return 0;
}