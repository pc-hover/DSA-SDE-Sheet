// Delete a given Node when a node is given.(0(1) solution)
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
void deleteNode(Node *&ptr)
{
    if (ptr != nullptr && ptr->next != nullptr)
    {
        ptr->data = (ptr->next)->data;
        ptr->next = ptr->next->next;
    }
    return;
}
void getNode(Node *&head, int n)
{
    Node *temp = head;
    while (temp->data != n)
    {
        temp = temp->next;
    }
    deleteNode(temp);
}
void display(Node *&head)
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    display(head);
    getNode(head, 2);
    display(head);
    return 0;
}
