#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node * Right;
    Node * Left;
    Node(int _data){
        data=_data;
        Right=Left=NULL;
    }
};
class Tree{
    private:
    Node * root;
    Node * getNodeByData(int data){
        Node * current =root;
        while(current != NULL ){
            if(data == current->data){
                return current;
            }else if(data > current->data){
                current=current->Right;
            }else{
                current=current->Left;
            }
        }
        return NULL;

    }
    Node * getParent(Node * node){
        Node * parent=root;
        while(parent != NULL){
            if(node == parent->Right ||node == parent->Left  ){
                return parent;
            }else if(node->data > parent->data){
                parent=parent->Right;
            }else{
                parent=parent->Left;
            }
        }
        return NULL;

    }

    Node * getMaxRight(Node * node){
        Node * current=node;
        while(current->Right != NULL){
            current=current->Right;
        }
        return current;
    }

    Node * getMinValue(){
    Node * Node =root;
    while(Node->Left != NULL){
    Node = Node-> Left;

    }
    return Node;
    }

        Node * getMaxValue(){
    Node * Node =root;
    while(Node->Right != NULL){
    Node = Node-> Right;

    }
    return Node;
    }

    public:
    Tree(){
        root=NULL;
    }
    void add(int data){
        Node * newNode=new Node(data);
        if(root == NULL){
            root=newNode;
        }
        else{
            Node * current = root;
            Node * parent = NULL;
            while(current != NULL){
                parent=current;
                if(data > current->data){

                    current=current->Right;
                }else{

                    current=current->Left;
                }
            }
            if(data>parent->data){
               parent->Right=newNode;
            }else{
                parent->Left=newNode;
            }

        }
    }
//=============================================================== assignment

    int findMinValue(){
    Node * Node =getMinValue();
    return Node->data;

    }
        int findMaxValue(){
    Node * Node =getMaxValue();
    return Node->data;

    }
    void removeData(int data){
    Node * node =getNodeByData(data);
    if(node ==NULL){
    throw "Data not found" ;}
    if(node == root){
    if(node ->Right ==NULL && node ->Left ==NULL){
    root ==NULL;
    }
    else if(node -> Right != NULL){
    node ->Right =root;
    }
   else if(node -> Left != NULL){
    node ->Left =root;
    }
    else {
    Node *newRoot =root -> Left;
    Node * MaxR =getMaxRight(newRoot);
    MaxR->Right =root->Right;
    root = newRoot;
    }
    }
    else {
    Node * parent =getParent(node);
    Node * newChild =NULL;
    if(node ->Right ==NULL && node ->Left ==NULL){
    newChild ==NULL;
    }
    else if(node -> Right != NULL){
    newChild =node ->Right;
    }
   else if(node -> Left != NULL){
    newChild =node ->Left;
    }
    else{
    Node *newParent =node->Left;
    Node*maxR=getMaxRight(newParent);
    maxR->Right=node->Right;
    newChild=newParent;
    }
    if(parent ->Right ==node){
    parent ->Right=newChild;
    }
    else {parent ->Left =newChild;}
}
delete node;

    }

};

int main()
{

Tree t;
int data;
    t.add(50);
    t.add(40);
    t.add(70);
    t.add(30);
    t.add(65);
    t.add(60);
    t.add(35);
    t.add(42);
    t.add(45);
    t.add(48);
    t.add(25);
    t.add(22);
    t.add(100);


  data = t.findMaxValue();
  cout<<data;
  try{
    t.removeData(1000);}
    catch (const char * msg){
    cout<<msg;}
  data = t.findMaxValue();
  cout<<data;


    return 0;
}

