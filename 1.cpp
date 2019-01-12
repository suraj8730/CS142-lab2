#include <iostream>
using namespace std;
class circle{
	public:
		//data
		int number;
		//pointer to the next circle
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
		void insertat(int pos, int value);
		void delet();
		void deleteat(int pos);
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
	//insert value in teh node
	tempo->number=num;
	//1st node only 
	if (head == NULL)
		head=tempo;
	//other node
	else
	{
		tail->nxt = tempo;
	}
	tail = tempo;
	}
	
void linkedlist::insertat(int pos, int value){
        // Reach the place before the pos
        circle * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->nxt;
        }

        // Create a circle
        circle * tempo = new circle;
        tempo -> number = value;


        // Moving ptrs like magic ! if not head
        tempo->nxt = current->nxt;
        current->nxt = tempo;
        
        // Update the code for 1st position

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
	l.display();
	l.delet();
	l.display();
    l.insertat(2,8);
    l.display();
	return 0;
}
