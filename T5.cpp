#include<iostream>
using namespace std;

class CircularQueue{
    int front, rear;
    int array[6];
public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if((rear+1)%6 == front){
            return true;   // fix: this IS the full condition (next slot would collide with front), was backwards before
        }else{
            return false;  // fix: not full otherwise
        }
    }

    bool isEmpty(){
        if(rear == -1){
            return true;
        }else{
            return false;
        }
    }

    void Enqueue(int val){
        if(isFull()){
            cout<<"Queue is Full\n";
            return;
        }else{
            if(rear == -1){
                front = 0;   // fix: front must also be initialized on the very first insert, was left at -1 before
                rear = 0;
                array[rear] = val;
            }else{
                rear = (rear+1)%6;
                array[rear] = val;
            }
        }
    }

    void Dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        }else{
            if(front == rear){
                front = rear = -1;
            }else{
                front = (front+1)%6;
            }
        }
    }

    void display(){
        if(isEmpty()){ 
            cout<<"Queue is Empty\n"; 
            return; 
        }
        int i = front;
        while(true){
            cout << array[i] << " ";
            if(i == rear) break;
            i = (i+1)%6;
        }
        cout << endl;
    }
};

int main(){
    CircularQueue q1;
    q1.Enqueue(101);
    q1.Enqueue(102);
    q1.Enqueue(103);
    q1.Enqueue(104);
    q1.Enqueue(105);
    q1.Enqueue(106);
    q1.display();
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    q1.display();
    q1.Enqueue(107);
    q1.Enqueue(108);
    q1.Enqueue(109);
    q1.display();
    q1.Dequeue();
    q1.Dequeue();
    q1.display();
    q1.Enqueue(110);
    q1.display();
    q1.Dequeue();
    q1.display();
    q1.Enqueue(111);
    q1.Enqueue(112);
    q1.display();
}