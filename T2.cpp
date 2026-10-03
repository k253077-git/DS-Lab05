#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor
{
private:
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(string word)
    {
        undoStack.push(word);
        while (!redoStack.empty()){
            redoStack.pop();
        }
    }

    void undo(){
        if (!undoStack.empty()){
            string word = undoStack.top();
            undoStack.pop();
            redoStack.push(word);
        }
    }

    void redo(){
        if (!redoStack.empty()){
            string word = redoStack.top();
            redoStack.pop();
            undoStack.push(word);
        }
    }

    void print(){
        stack<string> temp;
        stack<string> reverse;

        temp = undoStack;
        while (!temp.empty()){
            reverse.push(temp.top());
            temp.pop();
        }

        while (!reverse.empty()){
            cout << reverse.top() << " ";
            reverse.pop();
        }
        cout << endl;
    }
};

int main()
{
    TextEditor ed;

    ed.type("Hello");
    ed.print();
    ed.type("World");
    ed.print();

    ed.undo();
    ed.print();
    ed.redo();
    ed.print();
    ed.undo();
    ed.print();

    ed.type("There");
    ed.print();

    ed.redo();
    ed.print();

    return 0;
}
