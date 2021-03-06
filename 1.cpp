/*#CommentsMatter : Commenting should be used for every executable statement that does not perform trivial functions to non-CS person. 

Implement Singly Linked List using C++. Make sure the following functions: 
insert(int number) - Adds a new element to the end of the linked list. 
insertAt(int pos, int number) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or circle) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/
#include <iostream>
using namespace std;
class circle{
	public:
		//number
		int number;
		//pointer to the nxt circle
		circle * nxt;
		//constructor that makes the pointer part of the circle to null
		circle();
};
circle::circle(){
      nxt =NULL;
}
//class linked list
class linkedlist{
	public:
		//head  and circle inside linked list
		//head and tails are circle type pointers
		circle * head;
		circle * tail;
		//default constructor
		linkedlist();
		//circles are linked with each other so we have to decide how they get linked
		//inserting a circle
		void insert(int num);
		//inserting at a point
		void insertat(int pos, int value);
		//delete at end
		void delet();
		//delete at a position
		void deleteat(int pos);
		//count numer of circle in lnked list
		void count();
		//display
		void display();
	
};
linkedlist::linkedlist(){
	head= NULL;
	tail= NULL;
}
void linkedlist::insert(int num){
	//if 1st circle is added the
	circle * tempo = new circle;
	//insert value in teh circle
	tempo->number=num;
	//1st circle only 
	if (head == NULL)
		head=tempo;
	//other circle
	else
	{
		tail->nxt = tempo;
	}
	tail = tempo;
	}
	
void linkedlist::insertat(int pos, int value){
	// Create a circle
        circle * temp = new circle;
        temp -> number = value;
        // Reach the place before the pos
        circle * current = head;
        int i =1;
	// Update the code for 1st position
	if (pos==1){
		temp -> nxt = current;
		head = temp;
	}	
	else{
		int i =1;
		while(i < pos-1){
			if(current -> nxt == NULL){
				cout<<"Linked List does not have that many elements"<<endl;
				break;
			}
			else{
			i++;
			current = current->nxt;
			}
		}
		if(current -> nxt != NULL){
		// Moving ptrs like magic ! if not head
		temp->nxt = current->nxt;
		current->nxt = temp;
		}
	}
       }

    // Deletion of last element
void linkedlist::delet(){
        // store the tail in tempo
        circle * tempo = tail;
        // before tail has to point to null
        circle * current = head;
        while(current->nxt != tail){
            current = current->nxt;
        }
        current->nxt = NULL; 

        // update tail
        tail = current;
        // delete tempo
         delete tempo;
    }
void linkedlist::deleteat(int pos){
		//storing data of the head
		circle * current = head ;
		//for 1st position
		if(pos==1){
			head=current->nxt;
			delete current;
		}
		else{
			//finding twh position to delete
			int i=1;
			while(i<pos-1)
				{
				if(current -> nxt == NULL){
					cout<<"Linked List does not have that many elements"<<endl;
					break;
				}
				else{
				i++;
				current  = current-> nxt;
				}
			}
			if(current -> nxt != NULL){
				//storing the position to delete
				circle * del = current -> nxt;
				//pointing previous circle to nxt of the del(that we want to delete circle)
				current -> nxt = del -> nxt;
				delete del;
			}
		}	
}
//count
void linkedlist::count(){
	circle * current = head;
	int count=0;
        while(current != NULL){
            count++;
            current = current->nxt;
        }
        cout <<"Linked list have "<<count<<" elements"<< endl;
    }
// Display
void linkedlist::display(){
        circle * current = head;
        while(current != NULL){
            cout << current-> number << "->";
            current = current-> nxt;
        }
	
        cout << "NULL"<<endl;
    }

int main(){
	linkedlist l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(5);
    l.insert(1);
    l.display();
    l.deleteat(3);
    l.display();
    l.insertat(3,7);
    l.display();
    l.count();
	l.insertat(1,8);
	l.display();
	return 0;
}
