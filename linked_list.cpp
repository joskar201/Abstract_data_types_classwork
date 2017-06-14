/*
 * C++ Program to Implement Singly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*start;
 
/*
 * Class Declaration
 */
class single_llist
{
    public:
        node* create_node(int);
        void insert_begin();
        void display();
        void loadArray();
        single_llist() 
        {
            start = NULL;
        }
};
 
/*
 * Main :contains menu 
 */
main()
{
    int choice, nodes, element, position, i;
    single_llist sl;
    start = NULL;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Load the array"<<endl;
        cout<<"2.Display Linked List"<<endl;
        cout<<"3.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Loading array with data: "<<endl;
            sl.loadArray();
            cout<<endl;
            break;
        case 2:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 3:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
 
/*
 * Creating Node
 */
node *single_llist::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;     
        return temp;
    }
}

/*
 * Display Elements of a link list
 */
void single_llist::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

/*
*Load the even numbers ito the array
*/
void single_llist::loadArray()
{
    int* a = NULL;   // Pointer to int, initialize to nothing.
    cout<<"Enter the size of the array:"<<endl;
    int n;           // Size needed for array
    cin >> n;        // Read in the size
    a = new int[n];  // Allocate n ints and save ptr in a.
    for (int i=0; i<n; i++) {
    a[i] = 0;    // Initialize all elements to zero.
    }
    //enter even elements in array
    int elem;
    cout<<"Enter even numbers:"<<endl;
    for (int i=0;i<n;i++){
        cin>>elem;
        if(elem%2==0){
            a[i]=elem;
        }else{
            cout<<"Enter even numbers only!"<<endl;
            break;
        }
    }
    //put elements into the liked list;
    for (int i=0;i<n;i++){
        struct node *temp, *p;
        temp = create_node(a[i]);
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;          
        } 
        else
        {
            p = start;
            start = temp;
            start->next = p;
        }
    } 
    delete [] a;  // When done, free memory pointed to by a.
    a = NULL;
}