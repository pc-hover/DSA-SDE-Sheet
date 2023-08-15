#include <iostream>
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
Node *reverseKNode(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *cur = head;
    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    Node *dummy = new Node(0);
    dummy->next = head;

    Node *pre = dummy;
    Node *nex;
    while (count >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;

            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return dummy->next;
}
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
void printLinkedList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "\n";
}
int main()
{
    Node *head = NULL;
    int k = 3;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);

    cout << "Original Linked List: ";
    printLinkedList(head);
    cout << "After Reversal of k nodes: ";
    Node *newHead = reverseKNode(head, k);
    printLinkedList(newHead);

    return 0;
}