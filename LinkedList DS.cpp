#include <iostream>

using namespace std;

class Node{
public:
int data;
Node * next;
Node * prev;

public:
Node(int data){
this->data=data;
next = prev = NULL;
}

};
class LinkedList{
private:
Node * Head;
Node * Tail;
int counter;
public:
LinkedList(){
Head=Tail=NULL;
counter =0;


}

     void add(int data){
            Node *newNode=new Node(data);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            Tail->next = newNode;
            newNode->prev = Tail;
            Tail = newNode;
        }
        counter++;
    }



  void insertAfter(int data, int afterData) {
        Node* newNode = new Node(data);
        Node* current = Head;
        while (current != NULL) {
            if (current->data == afterData) {
                if (current == Tail) {
                    current->next = newNode;
                    newNode->prev = current;
                    Tail = newNode;
                } else {
                    newNode->next = current->next;
                    newNode->prev = current;
                    current->next->prev = newNode;
                    current->next = newNode;
                }
                counter++;
                return;
            }
            current = current->next;
        }
                cout << "Node with data " << afterData << " not found!" << endl;
        }

 void insertBefore(int data, int beforeData) {
        Node* newNode = new Node(data);
        Node* current = Head;
        while (current != NULL) {
            if (current->data == beforeData) {
                if (current == Head) {
                    newNode->next = current;
                    current->prev = newNode;
                    Head = newNode;
                } else {
                    newNode->next = current;
                    newNode->prev = current->prev;
                    current->prev->next = newNode;
                    current->prev = newNode;
                }
                counter++;
                return;
            }
            current = current->next;
        }
        cout << "Node with data " << beforeData << " not found!" << endl;
}
 void display(){
            Node * current=Head;
            if(current == NULL){
                cout<<"Linked List Is Empty : "<<endl;
                return;
            }
            while(current != NULL ){
                cout<<current->data<<"\t";
                current=current->next;
            }
            cout<<endl;

        }
        int getCounter(){
        return counter;
        }

   int GetDataByIndex(int index) {
        if (index < 0 || index >= counter) {
            cout << "Index out of bounds!" << endl;
            return -1;
        }

        Node* current = Head;
        int currentIndex =0;

        while (current != NULL) {
            if (currentIndex == index) {
                return current->data;
            }
            current = current->next;
            currentIndex++;
        }
        return -1;
    }

};





int main(){
int data;
LinkedList s1;
s1.add(1);
s1.insertAfter(100,1);
s1.display();
s1.insertAfter(30,1);
s1.display();
s1.insertAfter(50,100);
s1.display();
s1.insertAfter(500,30);
s1.display();
s1.insertBefore(1000,50);
s1.display();
s1.add(70);
s1.display();
s1.add(55);
s1.display();
data=s1.getCounter();
cout<<data<<endl;
data =s1.GetDataByIndex(8);
cout<<data<<endl;








return 0;
}
