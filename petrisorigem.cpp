#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* top = NULL;


void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}


void pop() {
    
    Node* temp = top;
    top = top->next;
    int poppedValue = temp->data;
    delete temp;
   
}

void procura(){
    Node* cur = top;
    
}
int main() {
    char input;
    int pilhas;

    cin >> pilhas;

    while (input != 'E')
    {
        cin >> input;
        if(input != 'E' && input != ' '){
            push((int)input);
        }
    }
    
    return 0;
}