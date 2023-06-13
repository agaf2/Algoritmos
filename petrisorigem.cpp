#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* bot = NULL;
Node* top = NULL;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int converte(string input)
{
    
    int num = 0;
    int n = input.length();
 
    for (int i = 0; i < n; i++)
 
        num = num * 10 + (int(input[i]) - 48);
 
    
    return num;
}


void pop(Node* cur) {
    
    Node* temp = cur;
    cur = cur->next;
    int poppedValue = temp->data;
    delete temp;
   
}

void procura(){
    Node* cur = top;
    while(cur != NULL){
        if(cur->data == cur->next->data){
            
        }
        if(cur-> next != NULL){
            cur->data = cur->next->data;
            cur->next = cur->next->next;
        }
        else{
            return;
        }
    }
}
int main() {
    string input;
    int pilhas;
    cin >> pilhas;

    while (input[0] != 'E')
    {
        cin >> input;
        if(input[0] != 'E' && input[0] != ' '){
            push(converte(input));
        }
    }

    procura();
    return 0;
}