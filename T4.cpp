#include<iostream>
using namespace std;

class node{
public:
    int val;
    node *next;

    node(){
        val = 0;
        next = NULL;
    }
};


class LinkedListQ{
public:
    node *head;
    node *tail;
    int NodeCount;
    int MaxNodes;

    LinkedListQ(){
        head = NULL;
        tail = NULL;
        NodeCount = 0;
        MaxNodes = 10;
    }

    bool isEmpty(){
        if (head == NULL){
            return true;
        }else{
            return false;
        }
    }    

    bool isFull(){
        if (NodeCount == MaxNodes){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int pVal){
        if (isFull()){
            cout << endl << "QUEUE is Full";
            return;
        }
        node *newNode = new node();
        newNode->val = pVal;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }

        else{
            tail->next = newNode;
            tail = newNode;
        }
        NodeCount++;
    }

    int dequeue(){
        if (isEmpty()){
            cout << endl << "QUEUE is Empty";
            return 0;
        }
        else{
            node *temp = head;
            head = head->next;
            int val = temp->val;
            delete temp;
            NodeCount--;
            return val;
            if (head == NULL){
                tail = NULL;
            }
        }
    }

    void printList(){
        if (isEmpty()){
            cout << endl << "QUEUE is Empty";
        }else{
            node *temp = head;
            cout << endl << "QUEUE = ";
            while (temp != NULL){
                cout << temp->val << ",  ";
                temp = temp->next;
            }
        }
    }
};

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedListS{
    Node*head;
    int Nodecount;
    int maxnodes;
public:
    LinkedListS(){
        head = NULL;
        maxnodes = 10;
        Nodecount = 0;
    }

    bool isEmpty(){
        return (Nodecount == 0);
    }

    bool isFull(){
        return (Nodecount == maxnodes);
    }

    void push(int val){
        if(isFull()){
            cout<<"Stack is Empty"<<endl;
            return;
        }else{
            Node*newnode = new Node(val);
            if(head == NULL){
                head = newnode;
                newnode->next = NULL; //is this line correct
            }else{
                newnode->next = head;
                head = newnode;
            
            }
            Nodecount++;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is Full";
            return 0;
        }else{
            Node *temp = head;
            head = head->next;
            int val = temp->data;
            delete temp;
            Nodecount--;
            return val;
        }
    }

    void printList(){
        if (isEmpty()){
            cout << endl << "STACK is Empty";
            return;
        }
        Node *temp = head;
        cout << endl << "TOP -> ";

        while (temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

void ReverseFirstK(LinkedListQ &q, LinkedListS &s, int K){
    int i=0; 
    int remaining = q.NodeCount - K;
    while(i<K){
        int val;
        val = q.dequeue();
        s.push(val);
        i++;
    }
    i=0;
    while(i<K){
        int val;
        val = s.pop();
        q.enqueue(val);
        i++;
    }
    i=0;
    while(i<remaining){
        int val;
        val = q.dequeue();
        q.enqueue(val);
        i++;
    }
    cout<<"\nDisplaying Correct queue"<<endl;
    q.printList();
}

int main(){
    LinkedListQ q1;
    LinkedListS s1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.printList();

    ReverseFirstK(q1,s1,3);
}

