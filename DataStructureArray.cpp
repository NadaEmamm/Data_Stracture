    #include <iostream>

    using namespace std;
    class QueueArray{
    int *items;
    int rear;
    int front;
    int size;
    public:
    QueueArray(int size){
    items =new int[size];
    this->size=size;
    front=rear=-1;
    }
    int isEmpty(){
    if(front == -1 && rear ==-1){
    return 1;
    }
    return 0;
    }
    int isFull(){
    if(front==0 && rear ==size-1){
    return 1;
    }
    if (rear == front -1)
    return 1;
    return 0;
    }
    int enqueue(int data){
    if (isFull())
    throw "Queue is full";
    if(isEmpty())
    front =rear=0;
    else if (rear ==size-1 && front !=0)
    rear =0;
    else
    rear ++;
    items[rear]=data;
    return 1;
    }
    int dequeue(){
    if(isEmpty())
    throw "Queue is empty";
    int data=items[front];
    if(rear==front)
    front =rear=-1;
    else if(front ==size-1)
    front =0;
    else
    front ++;
    return data;

    }
        void display() {
        if (isEmpty())
        throw "Queue is empty";
        int current = 0;
        while (current != size) {
            cout << items[current]<< " ";
            current++;
        }
        cout << "\n";
    }

    ~QueueArray(){
    delete [] items;
    }

    };
     //============================================================================== array by stack
     class Stack{
        private:
        int t;
        int size;
        int *values;

        public:
        Stack(int size){
        t =-1;
        this -> size = size;
        values = new int [size];
    };
        int push(int data){
        if(t == size-1)
        return 0;
        t++;
        values[t]=data;
        return 1;
    };
    void pop(int &dataShow) {
        if (t == -1) {
       throw "The stack is empty";
    }
          dataShow =values[t];
               t--;
    }

         void display(){
         if(t==-1)
       throw "The stack is empty";
         for(int i=0;i<=t;i++){
         cout<<values[i]<<endl;
         cout<<"============================================="<<endl;
        };

    }
     int peek(){
        if(t==-1)
        throw "The stack is empty";
        return values[t];
        }
    ~Stack (){
        delete[]values;
    };

    };
    int main()
    {

    int data;
        Stack test(3);
        test.push(5)?cout<<"Done"<<endl:cout<<"Failed"<<endl;
        test.push(2)?cout<<"Done"<<endl:cout<<"Failed"<<endl;
        test.push(1)?cout<<"Done"<<endl:cout<<"Failed"<<endl;
        test.push(1)?cout<<"Done"<<endl:cout<<"Failed"<<endl;

    cout<<"Display"<<endl;
         test.display();

         data=test.peek();
        cout<<"peek data = "<<data<<endl;



    try{
        test.pop(data);
        cout<<"Popped Data = "<<data<<endl;
        data=test.peek();
        cout<<"peek data = "<<data<<endl;
        test.pop(data);
        cout<<"Popped Data = "<<data<<endl;
        data=test.peek();
        cout<<"peek data = "<<data<<endl;
        test.pop(data);
        cout<<"Popped Data = "<<data<<endl;
        test.pop(data);
        cout<<"Popped Data = "<<data<<endl;

    }
        catch (const char * msg){
    cout<<msg<<endl;
    }
    try{
        test.display();
    }
        catch (const char * msg){
    cout<<msg<<endl;

    }
    //============================================================================== Queue test
    cout<<"Queue test"<<endl;
    QueueArray test2(3);
    try{
        test2.enqueue(33);
        test2.enqueue(11);
        test2.enqueue(12);
        test2.enqueue(1);
        }
  catch (const char * msg){
    cout<<msg<<endl;
       }
 test2.display();
    try{
      data=  test2.dequeue();
        cout<<data<<endl;
        data=  test2.dequeue();
        cout<<data<<endl;
        data=  test2.dequeue();
        cout<<data<<endl;
         data=  test2.dequeue();
        cout<<data<<endl;
        }
  catch (const char * msg){
    cout<<msg<<endl;
       }
    try{
        test2.display();

        }
  catch (const char * msg){
            cout<<msg<<endl;
       }


            return 0;
        }
