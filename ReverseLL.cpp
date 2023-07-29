#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *reverseLL(Node *&head)
{
    Node *temp = NULL;

    while (head != NULL)
    {
        Node *ptr2 = head->next;
        head->next = temp;
        temp = head;
        head = ptr2;
        // Node *ptr2 = head->next; Reason: then ptr2 is moving to NULL and then next-> of NULL also
    }
    return temp;
}
int main()
{
    Node *n1 = new Node(3);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 6);
    insertAtTail(tail, 8);
    insertAtTail(tail, 10);
    display(head);
    head = reverseLL(head);
    display(head);

    return 0;
}