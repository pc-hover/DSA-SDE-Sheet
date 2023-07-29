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

//    Time Complexity: O(n)
//   Space Complexity: O(1)
Node *middleElement(Node *&head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// TC->O(n)
// SC->O(1)
//  Node *middleElement(Node *&head)
//  {
//      Node *temp = head;
//      int ct = 1;
//      while (temp != NULL)
//      {
//          temp = temp->next;
//          ct++;
//      }
//      int m = ct / 2 + ct % 2;
//      ct = 1;
//      temp = head;
//      while (ct != m)
//      {
//          temp = temp->next;
//          ct++;
//      }
//      return temp;
//  }

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
    Node *n1 = new Node(3);
    Node *head = n1;
    Node *tail = n1;
    insertAtTail(tail, 6);
    insertAtTail(tail, 8);
    insertAtTail(tail, 10);
    display(head);

    head = middleElement(head);
    display(head);
    return 0;
}