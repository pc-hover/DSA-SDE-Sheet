#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *bottom;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->bottom = NULL;
        this->next = NULL;
    }
};
// Merge LinkedList
Node *MergeTwoLinkkedList(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}
Node *FlattenLL(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;
    // to reach reach last Node
    root->next = FlattenLL(root->next);

    // merge 2 Linkedlist
    root = MergeTwoLinkkedList(root, root->next);

    return root;
}
void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);

    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next->bottom = new Node(20);

    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    root = FlattenLL(root);

    cout << "Flattened Linked List: ";
    printList(root);

    return 0;
}