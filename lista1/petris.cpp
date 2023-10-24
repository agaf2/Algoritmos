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
        
    }
}

void pop(int index, int *pilhas){
    Node *temp = new Node();

    if(index == 1){
        temp = head->top;
        head->top = head->top->next;
        int poppedValue = temp->val;
        delete temp;
        if(head->top == NULL){
            Stack *curr = new Stack();
            Stack *aux = new Stack();
            aux = head;
            head = head->nextstack;
            curr = head;
            *pilhas = *pilhas - 1;
            delete aux;
            for(int i = 1; i < tail->index; i++ ){
                curr->index = curr->index - 1;
                curr = curr->nextstack;
            }
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
        
        if(curr->top == NULL && curr->nextstack == NULL){
            *pilhas = *pilhas - 1;
            aux->nextstack = NULL;
            tail = aux;
            delete curr;
            
        }

        else if(curr->top == NULL && curr->nextstack->top != NULL){
            aux->nextstack = curr->nextstack;
            *pilhas = *pilhas - 1;
            delete curr;
            aux = aux->nextstack;
            for(int i = aux->index; i <= tail->index; i++){
                aux->index = aux->index - 1;
                aux = aux->nextstack;
            }
            
        }
    }
    
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
            for(int i = 1; i < pilhas; i++ ){
                curr->index++;
                curr = curr->nextstack;
            }
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
    }

int procura(int index){
    Stack * curr = new Stack();
    curr = head;
    int print;
    while(curr->index != index)
        curr = curr->nextstack;
    print = curr->top->val;
    return print;
}

int main(){
    int games;
    int pilhas = 0;
    string index;
    int val;
    int printer = 0;
    int *ppilha = &pilhas ;
    
    cin >> games;

        while (games > 0)
        {
            while (index[0] != 'E')
            {
                cin >> index;
                
                if(index[0] != 'E' && index[0] != ' '){
                    cin >> val; 
                    if(converte(index) == 0 || pilhas == 0){
                            pilhas++;
                            insertAtStart(val, pilhas);
                    }
                    else if(converte(index) > pilhas){
                        pilhas++;
                        insertAtTail(val,pilhas);
                    }
                    else{
                        if(procura(converte(index)) != (val)){
                            push(val, converte(index));
                        }
                        else{
                            pop(converte(index), ppilha);                   
                        }    
                    }
                }   
            }
            
            games--;
            Stack * curr = new Stack();
            curr = head;
                cout <<"caso "<< printer<< ":";
                printer++;
                
                for(int i = 0; i < pilhas; i++){
                    Stack *aux = new Stack();
                    
                    
                    if(i != pilhas -1){
                    cout << " " << curr->top->val;
                    aux = curr;
                    curr = curr->nextstack;
                    head = curr;
                    delete aux;
                    }
                    else{
                        cout <<" " << curr->top->val;
                        aux = curr;
                        head = NULL;
                        tail = NULL;
                    }
                }
                index = 'a';
                pilhas = 0;
                cout << "\n";    
            }

    return 0;
}
