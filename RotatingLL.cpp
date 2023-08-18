#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
Node *rotateLL(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *cur = head;
    int count = 1;
    while (cur->next != NULL)
    {
        cur = cur->next;
        count++;
    }
    cur->next = head;
    k = count - k % count; // k can be greater than length
    while (k != 0)
    {
        cur = cur->next;
        k--;
    }
    head = cur->next;
    cur->next = NULL;

    return head;
}
// utility function to insert Node at the end of the list
void insertNode(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

// utility function to print list
void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << endl;
    return;
}

int main()
{
    Node *head = NULL;
    // inserting Node
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original list: ";
    printList(head);

    int k = 4;
    Node *newHead = rotateLL(head, k); // calling function for rotating right of   the Nodes by k times

    cout << "After " << k << " iterations: ";
    printList(newHead); // list after rotating Nodes
    return 0;
}