    #include <iostream>

    using namespace std;
    class StackNode{
    public:
    int data;
    StackNode * prev;
    StackNode (int data){
    this -> data =data;
    prev=NULL;
    }
    };
    class StackLinkedList{
    StackNode * tail;
    public:
    StackLinkedList(){
    tail=NULL;
    }
    void push(int data){
    StackNode *newNode =new StackNode(data);
    if (tail ==NULL){
        tail=newNode;
        return;
    }
    newNode ->prev =tail;
    tail = newNode;
    }
    int pop (){
    int data=0;
    if(tail == NULL)
    throw "Stack is Empty";

    StackNode *temp =tail;
    data = tail->data;
    tail = tail-> prev;
    delete temp;
    return data;

    }
    void display(){
    StackNode *current = tail;
    if(tail ==NULL)
        throw "Stack is Empty";
    while(current != NULL){
    cout<<current->data<<"  ";
    current =current ->prev;
    }
 cout<<"\n";
    }

    int peek(){
       if(tail == NULL)
    throw "Stack is Empty";
    return tail ->data;
    }

};
//================================================================== Queue on Linked list

    class QueueNode{
    public:
    int data;
    QueueNode * next;
    QueueNode(int data){
    this->data =data;
    next=NULL;
    }
    };

    class QueueLinkedList{
    QueueNode * front;
    QueueNode *rear;

    public:
    QueueLinkedList(){
    rear=front=NULL;
    }

    void enqueue(int data){
    QueueNode * newNode =new QueueNode(data);
    if (front == NULL){
    rear =front =newNode;
    return;
    }
    rear ->next =newNode;
    rear =newNode;
    }
    int dequeue (){
    int data =0;
    if(front == NULL)
    throw "Queue is Empty";
    QueueNode *temp =front;
    data=front->data;
    front =front ->next;
    if (front == NULL) {
         rear = NULL;
        }
    delete temp;
    return data;
    }
        void display() {
        if (front == NULL)
        throw "Queue is empty";
        QueueNode* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    };

int main()
{
    StackLinkedList stack;
    int data;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    try {
        cout << "Top element (peek): " << stack.peek() << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }

    cout << "Popping top element: " << stack.pop() << endl;
    cout << "Current stack after pop: ";
    stack.display();

    cout<<"Peeking after popping"<<endl;
        try {
    data =stack.peek();
    cout<<data<<endl;

    } catch (const char* msg) {
        cout << msg << endl;
    }



    cout << "Popping all elements:\n";
    try {
    data=stack.pop();
    cout<<data<<" ";
    data=stack.pop();
    cout<<data<<" ";
    data=stack.pop();

    } catch (const char* msg) {
        cout << msg << endl;
    }


    cout<<"Peeking after popping"<<endl;
        try {
            data =stack.peek();
            cout<<data<<endl;
    }
    catch (const char* msg) {
            cout << msg << endl;
    }
//============================================================================================ Queue Test

cout<<"===========================Queue Linked List========================="<<endl;
 QueueLinkedList queue;
    int data2;

    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);

    try {
    data=queue.dequeue() ;
    cout<<data<<endl;
    queue.display();

    data=queue.dequeue() ;
    cout<<data<<endl;
    queue.display();

     data=queue.dequeue() ;
     cout<<data<<endl;
     queue.display();



    } catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
