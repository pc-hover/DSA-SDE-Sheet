// Remove N-th node from the end of a Linked List
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
    Node()
    {
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
// TC --> O(n)
// SC --> O(1)
void RemoveNthNode(Node *&head, int n)
{
    Node *temp = new Node(); // this is a dummy node
    temp->next = head;
    Node *slow = temp;
    Node *fast = temp;
    int c = 0;
    while (c != n)
    {
        fast = fast->next;
        c++;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = (slow->next)->next;
    head = temp->next; // we updated the head since for corner case that in 5th element from last the head will change to nect of previous head or temp->next;
}
// void RemoveNthNode(Node *&head, int n)
// {
//     Node *curr = head;
//     Node *temp = head->next;
//     int ct = 0;
//     while (curr != NULL)
//     {
//         curr = curr->next;
//         ct++;
//     }
//     curr = head;
//     int x = 1;
//     if ((ct - (n - 1)) == 1)
//     {
//         head = curr->next;
//         delete (curr);
//         return;
//     }
//     ct = ct - (n - 1);

//     while (x != ct - 1)
//     {
//         curr = curr->next;
//         temp = temp->next;
//         x++;
//     }
//     curr->next = temp->next;
//     delete (temp);
//     return;
// }
int main()
{
    Node *n1 = new Node(1);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    display(head);
    RemoveNthNode(head, 5);
    display(head);
    return 0;
}