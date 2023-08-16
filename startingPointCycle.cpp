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
Node *startingPointCycle(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    // Find collison point
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
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

void createCycle(Node *&head, int pos)
{
    Node *ptr = head;
    Node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        if (cnt != pos)
        {
            ++cnt;
            ptr = ptr->next;
        }
        temp = temp->next;
    }
    temp->next = ptr;
}

int main()
{
    Node *head = NULL;

    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 3);
    insertNode(head, 6);
    insertNode(head, 10);

    createCycle(head, 2);

    cout << startingPointCycle(head)->data;
    return 0;
}