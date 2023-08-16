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
// BruteForce ->
// TC : O(N)
// SC : O(N)
// bool checkPalindromeLL(Node *&head)
// {
//     vector<int> array1;
//     Node *cur = head;
//     while (cur != NULL)
//     {
//         array1.push_back(cur->data);
//     }
//     cur = head;
//     int n = array1.size();
//     while (cur != NULL && n != 0)
//     {
//         if (cur->data == array1[n])
//         {
//             n--;
//             cur = cur->next;
//         }
//         else
//             return false;
//     }
//     return true;
// }
Node *reverseLL(Node *ptr)
{
    Node *pre = NULL;
    Node *nex = NULL;
    while (ptr != NULL)
    {
        nex = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nex;
    }
    return pre;
}
// TC-> 3*O(N/2)
// SC -> O(1)
bool checkPalindromeLL(Node *&head)
{
    if (head->next == NULL || head == nullptr)
        return true;

    // FIND THE MIDDLE
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // REVERSE HALF
    slow->next = reverseLL(slow->next);

    // COMPARE ELEMENTS
    slow = slow->next;
    Node *dummy = head;
    while (slow != NULL)
    {
        if (slow->data != dummy->data)
        {
            return false;
        }
        else
            dummy = dummy->next;
        slow = slow->next;
    }
    return true;
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
int main()
{
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);
    checkPalindromeLL(head) ? cout << "True" : cout << "False";

    return 0;
}