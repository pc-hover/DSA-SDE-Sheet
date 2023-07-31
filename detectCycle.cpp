#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
void createCycle(Node *&head, int a, int b)
{
    int cnta = 0, cntb = 0;
    Node *p1 = head;
    Node *p2 = head;
    while (cnta != a || cntb != b)
    {
        if (cnta != a)
            p1 = p1->next, ++cnta;
        if (cntb != b)
            p2 = p2->next, ++cntb;
    }
    p2->next = p1;
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
bool detectCycle(Node *&head)
{
    if (head->next == nullptr || head == nullptr)
        return false;

    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    createCycle(head, 1, 3); // creating cycle in the list
    if (detectCycle(head) == true)
        cout << "Cycle detected\n";
    else
        cout << "Cycle not detected\n";
    return 0;
}