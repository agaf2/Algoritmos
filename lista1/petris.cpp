#include <iostream>

using namespace std; 

struct Node
{
    int val;
    Node *next;
};

struct Stack
{
    Node *top;
    Stack *nextstack;
    int index;
};


Stack *head = NULL;
Stack *tail = NULL;

void push(int val,int index){
    Node *newNode = new Node();
    newNode->val = val;
    if(index == 1){
        newNode->next = head->top;
        head->top = newNode;
    }
    else{
        Stack *curr = new Stack();
        curr = head->nextstack;
        while(curr->index != index){
            curr = curr->nextstack;
        }
        newNode->next = curr->top;
        curr->top = newNode;
        delete curr;
    }
    delete newNode;
}

void pop(int index){
    Node *temp = new Node();

    if(index == 1){
        temp = head->top;
        head->top = head->top->next;
        int poppedValue = temp->val;
        delete temp;
        if(head == NULL){
            Stack *aux = new Stack();
            aux = head;
            head = head->nextstack;
            delete aux;
        }
    }
    else{
        Stack *curr = new Stack();
        Stack *aux = new Stack();
        curr = head->nextstack;
        aux = head;
        
        while(curr->index != index){
            curr = curr->nextstack;
            aux = aux->nextstack;
        }
        
        temp = curr->top;
        curr->top = curr->top->next;
        int poppedValue = temp->val;
        delete temp;
        
        if(curr == NULL && curr->nextstack != NULL){
            aux->nextstack = curr->nextstack;
            delete curr;
            delete aux;
        }
        else{
            delete curr;
            delete aux;
        }
    }
    delete temp;
}

int converte(string index)
{
    
    int num = 0;
    int n = index.length();
 
    for (int i = 0; i < n; i++)
 
        num = num * 10 + (int(index[i]) - 48);
 
    
    return num;
}

void insertAtStart(int val, int pilhas) {
        Stack* newStack = new Stack();
        Stack* curr = new Stack();
        if (head == nullptr) {
            head = newStack; 
            tail = newStack;
            head->index = 1;
            tail->index = 1;
        }
        else {
            newStack->nextstack = head;
            head = newStack;
            head->index = 1;
            curr = head->nextstack;
            delete newStack;
            for(int i = 1; i < pilhas; i++ ){
                curr->index++;
                curr = curr->nextstack;
            }
            delete curr;
        }   
        push(val, 1);
    }

void insertAtTail(int val, int pilhas) {
        Stack* newStack = new Stack();
        if (tail == nullptr) {
            head = newStack;
            tail = newStack;
        }
        else {
            tail->nextstack = newStack;
            tail = newStack;
            tail->index = pilhas;
        }
        push(val, pilhas);
        delete newStack;
    }

int main(){

    int pilhas;
    string index;
    int val;
    bool first = 1;
    int printer = 0;
    
    cin >> pilhas;

        while (index[0] != 'E')
        {
            cin >> index;
            if(index[0] != 'E' && index[0] != ' '){
                cin >> val; 
               if(converte(index) == 0){
                    pilhas++;
                    insertAtStart(val, pilhas);
               }
               else if(converte(index) > pilhas){
                pilhas++;
                insertAtTail(val,pilhas);
               }
               else{

               }
               // if(first ||  != (val)){
                 //   push(val, converte(index));
                   /// first = 0;
                //}
                //else{
                  //  pop(converte(index));                   
                //}    
            }
        }


    return 0;
}