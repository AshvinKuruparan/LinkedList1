#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
//Creating the nodes for the linked list
struct Node{
    string data;
    bool priority;
    Node *next;
};
// Queue class
class Queue {

    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void Enqueue(string element);
        void PriorityEnqueue(string element);
        string Dequeue();
        string toString ();
    private:
        Node *front;
        Node *back;
};
//Construtor
Queue::Queue(){
    front = NULL;
    back = NULL;
}
//Deconstructor 
Queue::~Queue(){
    while(!isEmpty()){
        cout << "Deleting Node\n";
        Dequeue();
    }
}
//Checks if the queue is empty 
bool Queue::isEmpty(){
    if (front == NULL && back == NULL){
        return true;
    }
    return false;
} 

//Adds element to back of queue
void Queue::Enqueue(string element){
    //Creates a new node for the element
    Node *newNode = new Node;
    newNode->data = element;
    newNode->priority = false;
    newNode->next = NULL;
    //Check if there is no front value
    if (front == NULL){
        front = newNode;
        back = newNode;
    }
    else{
        //Adds node to list
        back->next = newNode;
        back = newNode;
    }
}
//Adds element to front or behind previous priority queue
void Queue::PriorityEnqueue(string element){

    Node *ptr = front;
    int count = 0;
    //Counts how many other priority nodes there are
    while(ptr->priority == true){
        count++;
        ptr = ptr->next;
    }

    ptr = front;
    int count2 = count - 1;
    //Move to the back of the last priority node
    while (count2 > 1){
        ptr = ptr->next;
        count2--;
    }
    //Create new node
    Node *temp = new Node;
    temp->data = element;
    temp-> priority = true;
    //If there are no priority nodes
    if(count == 0){
        temp->next = ptr;
        front = temp;
    }
    else{
        temp->next = ptr->next;
        ptr->next = temp;
    } 
}

//Removes the front element from the queue and returns it as a string
string Queue::Dequeue(){
    if(isEmpty()){
        return "Queue is empty";
    }
    else if (front == back){
        //Checks if there is only one element
        string text = front->data;
        front = NULL;
        back = NULL;
        return text;

    }
    else{
        //Gets the front node then deletes it
        string text = front->data;
        Node *oldFront = front;
        front = front->next;
        delete oldFront;
        return text;
    }
}

//Converts queue to string
string Queue::toString(){
    if(isEmpty()){
        return "Queue is empty";
    }
    else
    {   
        Node *temp = front;
        string result = "";
        //Loops until there isn't anymore nodes
         while(temp != NULL){
            if (result == ""){
                result = temp->data; 
            }
            else{
                //Add the node to a string
                result = temp->data + " <- " + result;
            }
            //Move to next node
            temp = temp->next;
        }
        delete temp;
        //Return the string
        return result;
    }
    
}

int main() {

    Queue* q = new Queue();

    q->Enqueue("Solo");
    q->Enqueue("R2D2");
    q->Enqueue("Yoda");
    q->PriorityEnqueue("BB8");

    cout << q->toString() << endl;

    q->Dequeue();

    cout << q->toString() << endl;

    delete q;

    return 0;
}