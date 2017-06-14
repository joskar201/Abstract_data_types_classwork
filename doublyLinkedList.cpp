#include<iostream> 
#include<string>
using namespace std;

/* Linked list structure */
struct list {
	struct list *prev;
	string data;
	struct list *next;
} *node = NULL, *first = NULL, *last = NULL, *node1 = NULL, *node2 = NULL;

class linkedlist {
	public: 

		/* Function for create/insert node at the beginning of Linked list */
		void insert_beginning() {
			list *addBeg = new list;
			cout << "Enter value for the node:" << endl;
			cin >> addBeg->data;
			if(first == NULL) {
				addBeg->prev = NULL;
				addBeg->next = NULL;
				first = addBeg;
				last = addBeg;
				cout << "Linked list Created!" << endl;
			}
			else {
				addBeg->prev = NULL;
				first->prev = addBeg;
				addBeg->next = first;
				first = addBeg;
				cout << "Data Inserted at the beginning of the Linked list!" << endl;
			}
		}

		/* Function for create/insert node at the end of Linked list */
		void insert_end() {
			list *addEnd = new list;
			cout << "Enter value for the node:" << endl;
			cin >> addEnd->data;
			if(first == NULL) {
				addEnd->prev = NULL;
				addEnd->next = NULL;
				first = addEnd;
				last = addEnd;
				cout << "Linked list Created!" << endl;
			}
			else {
				addEnd->next = NULL;
				last->next = addEnd;
				addEnd->prev = last;
				last = addEnd;
				cout << "Data Inserted at the end of the Linked list!" << endl;
			}
		}

		/* Function for Display Linked list */
		void display() {
			node = first;
			cout << "List of data in Linked list in input order!" << endl;
			while(node != NULL) {
				cout << node->data << endl;
				node = node->next;
			}
			node = last;
			cout << "List of data in Linked list in reverse order!" << endl;
			while(node != NULL) {
				cout << node->data << endl;
				node = node->prev;
			}
		}
};
int main() {
	int op = 0;
	linkedlist llist = linkedlist();
	while(op != 4) {
		cout << "1. Insert at the beginning\n2. Insert at the end\n3. Display\n5. Exit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> op;
		switch(op) {
			case 1:
				llist.insert_beginning();
				break;
			case 2:
				llist.insert_end();
				break;
			case 3:
				llist.display();
				break;
			case 5:
				cout << "Bye Bye!" << endl;
				return 0;
				break;
			default:
				cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}

