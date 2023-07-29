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
Node *Add2Nums(Node *&h1, Node *&h2)
{
    Node *ans = new Node();
    Node *temp = ans;
    int carry = 0;

    while (h1 != NULL || h2 != NULL || carry)
    {
        int sum = 0;
        if (h1 != NULL)
        {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2 != NULL)
        {
            sum += h2->data;
            h2 = h2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node *x = new Node(sum % 10);
        temp->next = x;
        temp = temp->next; //!!
    }
    return ans->next;
}
int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node *head2 = new Node(4);
    head2->next = new Node(15);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(3);

    display(head1);
    display(head2);
    display(Add2Nums(head1, head2));
}
