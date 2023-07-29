#include <bits/stdc++.h>
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
Node *mergeSortedLL(Node *&l1, Node *&l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    if (l1->data > l2->data)
        swap(l1, l2);
    Node *res = l1;

    while (l1 != NULL && l2 != NULL)
    {
        Node *temp = NULL;
        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
}

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
int main()
{
    Node *n1 = new Node(1);
    Node *head1 = n1;
    Node *tail = n1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 4);
    display(head1);

    Node *n2 = new Node(1);
    Node *head2 = n2;
    Node *tail2 = n2;
    insertAtTail(tail2, 1);
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);
    display(head2);

    Node *head = mergeSortedLL(head1, head2);
    display(head);
    return 0;
}