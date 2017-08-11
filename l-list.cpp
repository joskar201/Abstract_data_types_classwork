#include <iostream>

using namespace std;

struct node
{
    int numbers;
    node *next
};

bool isEmpty (node *head);
char menu();
node insertAsFirstElement (node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void remove (node *&head, node *&last);
void showlist (node *current);

bool isEmpty(node *head)
{
    if (head == NULL)
    {
        return true
    }
    else {
        return false
    }
}

node insertAsFirstElement (node *&head, node *&last, int number)
{
    node *temp = new node;
    temp->number = number;
    temp->next= NULL;
    head = temp
}
void insert(node *&head, node *&last, int number)
{
    if (IsEmpty(head))
    insertAsFirstElement(head,last,number);
    else
    {
    node *temp = new node;
    temp->number = number;
    temp->next = NULL;
    last->next=temp
    }
}
void remove (node *&head, node *&last)
{
    if (IsEmpty(head))
    cout<<"this list empty"<<endl;

    else if(head == last)
    {
        delete head;
        head = NULL;
        last
    }
}
