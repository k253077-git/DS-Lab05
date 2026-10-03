#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Queue{
private:
    queue<int> q;

public:

    void enqueue(int value){
        q.push(value);
    }

    void dequeue(){
        if (!q.empty()){
            q.pop();
        }
    }

    int front(){
        return q.front();
    }

    bool isEmpty(){
        return q.empty();
    }

    int size(){
        return q.size();
    }

    void print(){
        queue<int> temp = q;

        while (!temp.empty()){
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

void reverseFirstK(Queue &q, int k){
    if (k<=0 || k>q.size()){
        return;
    }

    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.dequeue();
    }
    while (!s.empty()){
        q.enqueue(s.top());
        s.pop();
    }

    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++){
        q.enqueue(q.front());
        q.dequeue();
    }
}

int main(){
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout << "Original Queue: ";
    q.print();

    reverseFirstK(q, 3);

    cout << "After reversing first 3 elements: ";
    q.print();

    return 0;
}
