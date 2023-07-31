// List 1 = [1,3,1,2,4], List 2 = [3,2,4]
#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
void display(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode *intersectionListNode(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    ListNode *a = head1;
    ListNode *b = head2;

    while (a != b)
    {
        a = a == NULL ? head2 : a->next;
        b = b == NULL ? head1 : b->next;
    }
    return a; // if a and b are both NULL the while loop will stop and return a that is NUll
}
int main()
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(2);

    ListNode *head2 = new ListNode(3);
    head2->next = head1->next->next->next; // linked Listnode is 2

    head1->next->next->next->next = new ListNode(4);

    head2->next->next = head1->next->next->next->next;

    display(head1);
    display(head2);
    cout << (intersectionListNode(head1, head2))->data;
}