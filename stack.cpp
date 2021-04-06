#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Create a node struct to store
//one item of data in the Stack class
struct Node {
  string data;
  Node *next; //points to the next node in the Stack
};

class Stack {
  public:
    Stack(); //constructor
    ~Stack(); //deconstructor
    bool isEmpty() {return (top == NULL);}; //Check if stack is isEmpty
    void push(string d); //pushes a node containing d
                         //onto the top of the Stack
    string pop(); //Pop the top node off of the stack
                  //and return the string stored in the node
    string toString(); //save Stack contents to a string
  private:
    Node *top; //points to the top item in the Stack
};

Stack::Stack() {
  top = NULL; //initialize to an empty Stack
              //(i.e. a Stack that has top point to nothing)
}

Stack::~Stack() {
  //Has to free up all of the memory allocated to nodes in the Stack
  while (!isEmpty()) {
    cout << "deleting node\n";
    pop();
  }
}

void Stack::push(string d) {
  Node *newtop = new Node;
  newtop->data = d;
  newtop->next = top; //points the new node's next to the
                      //old top of the Stack
  top = newtop; //makes the new node the top of the stack
}

string Stack::pop() {
  if (isEmpty()) {
    cout << "ERROR: you can't pop from an empty stack!" << endl;
    exit(1);
  } else {
    string value = top->data; //set aside current value of top
    Node *oldtop = top; //create oldtop to point to top
    top = top->next; //reassign the top of the stack to the
                     //second top element (i.e. one below the old top)
    delete oldtop; //delete the node being popped
    return value; //return value of popped node
  }
}

string Stack::toString() {
  string result = "(top) -> ";
  Node *current = top;
  while (current != NULL) {
    result += current->data + " -> ";
    current = current->next;
  }
  result += "NULL";
  return result;
}

int main() {
  Stack *s = new Stack();
  cout << s->toString() << endl;
  s->push("Orange");
  s->push("Apple");
  s->push("Banana");
  cout << s->toString() << endl;
  if (!s->isEmpty()) {
    s->pop();
  }
  cout << s->toString() << endl;
  delete s;
  return 0;
}