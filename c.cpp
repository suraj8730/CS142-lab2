#include<iostream> 
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }

};

class LinkedList{
    // Head + Circles inside linked with each other
    public:
    // Head -> Node type ptr
    Node * head;
    Node * tail;

    // Construct
    LinkedList(){
        head = NULL;
        tail = NULL;
    } 
    // Circles inside linked with each other
    // Rules how circles will be linked

    // Insert
    void insert(int value){
       // If 1st Node is added
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL){
            head = temp;
       }
       // Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    } 
// Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }
//Reverse the linked list
	void revLL(){
		Node * temp =head;
		revLL2(head);
		temp->next = NULL;
		cout<<endl;
	}
	void revLL2(Node * current){
		//condition for empty LL
		if(current == NULL) return;
		//condition for one element
		else if(current -> next == NULL){
			head = current;
			cout<<current->data<<"->";
			return;
		}
		//reerse for rest
		else{
			revLL2(current->next);
			current->next->next = current;
			cout<<current->data<<"->";
		}
	}

};
int main(){
    LinkedList l1;
	for(int i=1;i<10;i++){
		l1.insert(i);
}
	l1.revLL();
	l1.display();
    return 0;
}
