#include <iostream>
using namespace std;

# define size 6
class stack{
	int top;
    int a[size];
public:
    stack(){
	 top = -1; 
	}
	
	bool isfull(){
		return top>=size-1;
	}
	bool isempty(){
		return top<0;
	}
	
	void push(int val){
		if(isfull()){
			cout<<"Stack overflow";
		}else{
			top++;
			a[top]=val;
			cout<<val<<" pushed in stack";
		}
		cout<<endl;
	}
	
	void pop(){
		if(isempty()){
			cout<<"Stack underflow";
		}else{
			cout<<a[top]<<" poped";
			top--;
		}
		cout<<endl;
	}
	int peek() {
        if (isempty()){
        	cout<<"Stack is empty";
        	return -1;
        }
        return a[top];
        cout<<endl;
    }
};
int main(){
	stack s1;
	s1.push(12);
	s1.push(25);
	s1.push(17);
	s1.push(31);
	s1.push(44);
	s1.push(19);
	
	cout<<"top val"<<s1.peek();
	
	s1.pop();
	s1.pop();
	s1.pop();
	
	cout<<"top val"<<s1.peek();
	
}
